#pragma once
#include <unordered_map>
#include "enschin/graphics/effects/color.hpp"
#include "enschin/graphics/model.h"
#include "enschin/graphics/texture.h"

struct Ressources {
public:
    ~Ressources() {
        for (auto model = models.begin(); model != models.end(); model++) model->second.free();
        for (auto texture = textures.begin(); texture != textures.end(); texture++) texture->second.free();
    }
    void load(std::string ressourcePath);
    std::unordered_map<std::string, Model> models;
    std::unordered_map<std::string, Texture> textures;
    std::unordered_map<std::string, Color> colors;
};