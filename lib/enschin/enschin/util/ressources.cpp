#include <iostream>
#include "ressources.h"

Ressources::Ressources(std::string ressourcePath) {
    load(ressourcePath);
}

Ressources::~Ressources() {
    free();
}

void Ressources::free() {
    for (auto model = models.begin(); model != models.end(); model++) model->second.free();
    for (auto texture = textures.begin(); texture != textures.end(); texture++) texture->second.free();
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
                models.insert({(*m)["name"].asString(), Model({
                                                                  (*m)["width"].asFloat(),
                                                                  (*m)["height"].asFloat()
                                                          })});
            }
        }
    }
    for (int i = 0; i < ressourceValues["sprite_sheets"].size(); i++) {
        std::ifstream textureStream(ressourceValues["sprite_sheets"][i].asString(), std::ifstream::binary);
        Json::Reader textureReader;
        Json::Value textureValues;
        textureReader.parse(textureStream, textureValues);
        for (auto t = textureValues.begin(); t != textureValues.end(); ++t) {
            if (0) {

            }else {
                textures.insert({t.key().asString(), (*t)["texture"].asString()});
            }
        }
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