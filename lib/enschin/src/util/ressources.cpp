#include <enschin/ressources.h>

Ressources::Ressources(std::string ressourcePath) {
    load(std::move(ressourcePath));
}

Ressources::~Ressources() {
    for (auto& model : models) delete model.second;
    for (auto& spriteSheet : spriteSheets) delete spriteSheet.second;
    for (auto& sprite : sprites) delete sprite.second;
    for (auto& terrain : terrainDefinitions) delete terrain.second;
    for (auto& color: colors) delete color.second;
}

void Ressources::load(std::string ressourcePath) {
    std::ifstream ressourceStream(ressourcePath, std::ifstream::binary);
    Json::Reader ressourceReader;
    Json::Value ressourceValues;
    ressourceReader.parse(ressourceStream, ressourceValues);
    if (ressourceValues.isMember("ressources")) {
        for (int i = 0; i < ressourceValues["ressources"].size(); i++) {
            load(ressourceValues["ressources"][i].asString());
        }
    }
    if (ressourceValues.isMember("colors")) {
        for (int i = 0; i < ressourceValues["colors"].size(); i++) {
            std::ifstream colorStream(ressourceValues["colors"][i].asString(), std::ifstream::binary);
            Json::Reader colorReader;
            Json::Value colorValues;
            colorReader.parse(colorStream, colorValues);
            for (auto c = colorValues.begin(); c != colorValues.end(); c++) {
                const std::string key = c.key().asString();
                colors.insert({key, new Color(
                        (*c)[0].asFloat(),
                        (*c)[1].asFloat(),
                        (*c)[2].asFloat(),
                        (*c)[3].asFloat()
                )});
            }
        }
    }
    if (ressourceValues.isMember("terrains")) {
        for (int i = 0; i < ressourceValues["terrains"].size(); i++) {
            std::ifstream terrainStream(ressourceValues["terrains"][i].asString(), std::ifstream::binary);
            Json::Reader terrainReader;
            Json::Value terrainValues;
            terrainReader.parse(terrainStream, terrainValues);
            for (auto t = terrainValues.begin(); t != terrainValues.end(); t++) {
                float* worldVertices = jsonToFloatArray((*t)["vertices"], (*t)["amount_of_vertices"].asUInt() * 4);
                terrainDefinitions.insert({t.key().asString(), new TerrainDefinition(worldVertices, (*t)["amount_of_vertices"].asInt())});
                delete worldVertices;
            }
        }
    }
    if (ressourceValues.isMember("models")) {
        for (int i = 0; i < ressourceValues["models"].size(); i++) {
            std::ifstream modelStream(ressourceValues["models"][i].asString(), std::ifstream::binary);
            Json::Reader modelReader;
            Json::Value modelValues;
            modelReader.parse(modelStream, modelValues);
            for (auto m = modelValues.begin(); m != modelValues.end(); m++) {
                if (m->isMember("amount_of_vertices")) {
                    float *vertices = jsonToFloatArray((*m)["vertices"], (*m)["amount_of_vertices"].asInt() * 4);
                    unsigned int *indices = jsonToUIntArray((*m)["indices"], (*m)["amount_of_indices"].asInt());
                    models.insert({m.key().asString(), new Model(
                            vertices,
                            false,
                            (*m)["amount_of_vertices"].asInt(),
                            indices,
                            (*m)["amount_of_indices"].asInt()
                    )});
                    delete vertices, delete indices;
                } else if (m->isMember("width")) {
                    models.insert({m.key().asString(), new Model({
                                                                     (*m)["width"].asFloat(),
                                                                     (*m)["height"].asFloat()
                                                             })});
                } else if (m->isMember("radius")) {
                    models.insert({m.key().asString(), new Model((*m)["radius"].asFloat())});
                }
            }
        }
    }
    if (ressourceValues.isMember("sprite_sheets")) {
        for (int i = 0; i < ressourceValues["sprite_sheets"].size(); i++) {
            std::ifstream spriteSheetStream(ressourceValues["sprite_sheets"][i].asString(), std::ifstream::binary);
            Json::Reader spriteSheetReader;
            Json::Value spriteSheetValues;
            spriteSheetReader.parse(spriteSheetStream, spriteSheetValues);
            for (auto s = spriteSheetValues.begin(); s != spriteSheetValues.end(); ++s) {
                spriteSheets.insert({s.key().asString(), new SpriteSheet(
                        (*s)["texture"].asString(),
                        {(*s)["sprite_width"].asFloat(),(*s)["sprite_height"].asFloat()},
                        (*s)["fps"].asInt()
                )});
            }
        }
    }
    if (ressourceValues.isMember("sprites")) {
        for (int i = 0; i < ressourceValues["sprites"].size(); i++) {
            std::string texturePath = ressourceValues["sprites"][i].asString();
            std::string fileNameWithExtension = texturePath.substr(texturePath.find_last_of("/\\") + 1);
            std::string fileNameWithoutExtension = fileNameWithExtension.substr(0, (fileNameWithExtension.find_last_of('.')));
            sprites.insert({fileNameWithoutExtension, new Sprite(texturePath)});
        }
    }
}

unsigned int* Ressources::jsonToUIntArray(const Json::Value& jsonArray, unsigned int size) {
    auto* output = new unsigned int[size];
    for (int i = 0; i < size; i++) {
        output[i] = jsonArray[i].asUInt();
    }
    return output;
}

float* Ressources::jsonToFloatArray(const Json::Value& jsonArray, unsigned int size) {
    auto* output = new float[size];
    for (int i = 0; i < size; i++) {
        output[i] = jsonArray[i].asFloat();
    }
    return output;
}