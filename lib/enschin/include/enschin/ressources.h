#pragma once
#include <unordered_map>
#include <json/json.h>
#include <fstream>
#include "color.h"
#include "model.h"
#include "texture.h"
#include "sprite.h"
#include "terrain.h"

struct Ressources {
private:
    static float* jsonToFloatArray(const Json::Value& jsonArray, unsigned int size);
    static unsigned int* jsonToUIntArray(const Json::Value& jsonArray, unsigned int size);
    std::unordered_map<std::string, Terrain*> terrains;
    std::unordered_map<std::string, Model> models;
    std::unordered_map<std::string, SpriteSheet> spriteSheets;
    std::unordered_map<std::string, Sprite> sprites;
    std::unordered_map<std::string, Color> colors;
public:
    Ressources() = default;
    Ressources(std::string ressources);
    void load(std::string);
    void free() const;
    Model& getModel(std::string key) const{ return const_cast<Model &>(models.at(key)); }
    SpriteSheet& getSpriteSheet(std::string key) const { return const_cast<SpriteSheet &>(spriteSheets.at(key)); }
    Color& getColor(std::string key) const { return const_cast<Color &>(colors.at(key)); }
    Sprite& getSprite(std::string key) const { return const_cast<Sprite &>(sprites.at(key)); }
    Terrain& getTerrain(std::string key) const { return const_cast<Terrain &>(*terrains.at(key)); }
};