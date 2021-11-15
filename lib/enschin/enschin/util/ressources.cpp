#include "ressources.h"

Ressources::Ressources(std::string ressourcePath) {
    load(ressourcePath);
}

Ressources::~Ressources() {
    free();
}

void Ressources::free() {
    for (auto model = models.begin(); model != models.end(); model++) model->second.free();
    for (auto spriteSheet = spriteSheets.begin(); spriteSheet != spriteSheets.end(); spriteSheet++) spriteSheet->second.free();
    for (auto sprite = sprites.begin(); sprite != sprites.end(); sprite++) sprite->second.free();
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
        for (auto m = modelValues.begin(); m != modelValues.end(); ++m) {
            if (m->isMember("amountOfVertices")) {
                float* vertices = new float[(*m)["amountOfVertices"].asInt()*2];
                jsonToArray(vertices, (*m)["vertices"],(*m)["amountOfVertices"].asInt()*2);
                unsigned int* indices = new unsigned int[(*m)["amountOfIndices"].asInt()];
                jsonToArray(indices, (*m)["indices"],(*m)["amountOfIndices"].asInt());
                models.insert({m.key().asString(), Model(
                        vertices,
                        (*m)["amountOfVertices"].asInt(),
                        indices,
                        (*m)["amountOfIndices"].asInt()
                )});
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
                    (*s)["fps"].asFloat()
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

void Ressources::jsonToArray(unsigned int output[], Json::Value jsonArray, unsigned int size) {
    for (int i = 0; i < size; i++) {
        output[i] = jsonArray[i].asUInt();
    }
}

void Ressources::jsonToArray(float output[], Json::Value jsonArray, unsigned int size) {
    for (int i = 0; i < size; i++) {
        output[i] = jsonArray[i].asFloat();
    }
}