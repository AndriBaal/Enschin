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
    std::unordered_map<std::string, const Terrain*> terrains;
    std::unordered_map<std::string, const Model*> models;
    std::unordered_map<std::string, const SpriteSheet*> spriteSheets;
    std::unordered_map<std::string, const Sprite*> sprites;
public:
    Ressources() = default;
    Ressources(std::string ressources);
    ~Ressources();
    void load(std::string);
    const Model& getModel(const std::string& key) const { return  *models.at(key); }
    const SpriteSheet& getSpriteSheet(const std::string& key) const { return *spriteSheets.at(key); }
    const Sprite& getSprite(const std::string& key) const { return *sprites.at(key); }
    const Terrain& getTerrain(const std::string& key) const { return *terrains.at(key); }
};