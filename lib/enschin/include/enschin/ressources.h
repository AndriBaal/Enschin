#pragma once
#include <unordered_map>
#include <json/json.h>
#include <fstream>
#include "color.h"
#include "model.h"
#include "texture.h"
#include "sprite.h"

struct Ressources {
private:
    void jsonToArray(float output[], Json::Value jsonArray, unsigned int size);
    void jsonToArray(unsigned int output[], Json::Value jsonArray, unsigned int size);
    std::unordered_map<std::string, Model> models;
    std::unordered_map<std::string, SpriteSheet> spriteSheets;
    std::unordered_map<std::string, Sprite> sprites;
    std::unordered_map<std::string, Color> colors;
public:
    Ressources() = default;
    Ressources(std::string ressources);
    void load(std::string);
    void free();
    Model& getModel(std::string key){ return models.at(key); }
    SpriteSheet& getSpriteSheet(std::string key){ return spriteSheets.at(key); }
    Color& getColor(std::string key){ return colors.at(key); }
    Sprite& getSprite(std::string key){ return sprites.at(key); }
};