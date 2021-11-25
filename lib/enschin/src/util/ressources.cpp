#include <iostream>
#include <enschin/ressources.h>

Ressources::Ressources(std::string ressourcePath) {
    load(std::move(ressourcePath));
}


void Ressources::free() const {
    for (auto& model : models) model.second.free();
    for (auto& spriteSheet : spriteSheets) spriteSheet.second.free();
    for (auto& sprite : sprites) sprite.second.free();
}

void Ressources::load(std::string ressourcePath) {
    std::ifstream ressourceStream(ressourcePath, std::ifstream::binary);
    Json::Reader ressourceReader;
    Json::Value ressourceValues;
    ressourceReader.parse(ressourceStream, ressourceValues);
    for (int i = 0; i < ressourceValues["models"].size(); i++) {
        std::ifstream modelStream(ressourceValues["models"][i].asString(), std::ifstream::binary);
        Json::Reader modelReader;
        Json::Value modelValues;
        modelReader.parse(modelStream, modelValues);
        for (auto m = modelValues.begin(); m != modelValues.end(); m++) {
            if (m->isMember("amountOfVertices")) {
                float *vertices = jsonToFloatArray((*m)["vertices"],(*m)["amountOfVertices"].asInt()*4);
                unsigned int *indices = jsonToUIntArray((*m)["indices"],(*m)["amountOfIndices"].asInt());
                models.insert({m.key().asString(), Model(
                        vertices,
                        (*m)["amountOfVertices"].asInt(),
                        indices,
                        (*m)["amountOfIndices"].asInt()
                )});
                delete vertices, delete indices;
            } else if (m->isMember("width")) {
                models.insert({m.key().asString(), Model({
                                                      (*m)["width"].asFloat(),
                                                      (*m)["height"].asFloat()
                                              })});
            }
        }
    }
    for (int i = 0; i < ressourceValues["sprite_sheets"].size(); i++) {
        std::ifstream spriteSheetStream(ressourceValues["sprite_sheets"][i].asString(), std::ifstream::binary);
        Json::Reader spriteSheetReader;
        Json::Value spriteSheetValues;
        spriteSheetReader.parse(spriteSheetStream, spriteSheetValues);
        for (auto s = spriteSheetValues.begin(); s != spriteSheetValues.end(); ++s) {
            spriteSheets.insert({s.key().asString(), SpriteSheet(
                    (*s)["texture"].asString(),
                    {(*s)["sprite_width"].asFloat(),(*s)["sprite_height"].asFloat()},
                    (*s)["fps"].asInt()
                    )});
        }
    }
    for (int i = 0; i < ressourceValues["sprites"].size(); i++) {
        std::string texturePath = ressourceValues["sprites"][i].asString();
        std::string fileNameWithExtension = texturePath.substr(texturePath.find_last_of("/\\") + 1);
        std::string fileNameWithoutExtension = fileNameWithExtension.substr(0, (fileNameWithExtension.find_last_of('.')));
        sprites.insert({fileNameWithoutExtension, Sprite(texturePath)});
    }
}

unsigned int* Ressources::jsonToUIntArray(const Json::Value& jsonArray, unsigned int size) const{
    auto* output = new unsigned int[size];
    for (int i = 0; i < size; i++) {
        output[i] = jsonArray[i].asUInt();
    }
    return output;
}

float* Ressources::jsonToFloatArray(const Json::Value& jsonArray, unsigned int size) const{
    auto* output = new float[size];
    for (int i = 0; i < size; i++) {
        output[i] = jsonArray[i].asFloat();
    }
    return output;
}