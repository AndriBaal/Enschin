#pragma once
#include <unordered_map>
#include <json/json.h>
#include <fstream>
#include "enschin/graphics/effects/color.hpp"
#include "enschin/graphics/model.h"
#include "enschin/graphics/texture.h"
#include "enschin/graphics/sprite_sheet.h"

struct Ressources {
private:
    void jsonToArray(float output[], Json::Value jsonArray, unsigned int size);
    void jsonToArray(unsigned int output[], Json::Value jsonArray, unsigned int size);
    std::unordered_map<std::string, Model> models;
    std::unordered_map<std::string, SpriteSheet> spriteSheets;
    std::unordered_map<std::string, Color> colors;
public:
    Ressources() = default;
    Ressources(std::string ressources);
    ~Ressources();
    void load(std::string);
    void free();
    Model& getModel(std::string key){ return models.at(key); }
    SpriteSheet& getSpriteSheet(std::string key){ return spriteSheets.at(key); }
    Color& getColor(std::string key){ return colors.at(key); }
};