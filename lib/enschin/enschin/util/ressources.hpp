#pragma once
#include <unordered_map>
#include <string>
#include "enschin/graphics/effects/color.hpp"
#include "enschin/graphics/model.h"
#include "enschin/graphics/texture.h"

struct Ressources {
public:
    std::unordered_map<std::string, Model> models;
    std::unordered_map<std::string, Texture> textures;
    std::unordered_map<std::string, Color> colors;
    virtual void load() = 0;
};