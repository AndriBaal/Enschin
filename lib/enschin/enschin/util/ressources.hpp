#pragma once
#include <map>
#include <string>
#include "enschin/graphics/effects/color.hpp"
#include "enschin/graphics/model.h"
#include "enschin/graphics/texture.h"

struct Ressources {
public:
    std::map<std::string, Model> models;
    std::map<std::string, Texture> textures;
    std::map<std::string, Color> colors;
    virtual void load() = 0;
};