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
    std::unordered_map<std::string, const Terrain> terrains;
    std::unordered_map<std::string, const Model*> models;
    std::unordered_map<std::string, const SpriteSheet*> spriteSheets;
    std::unordered_map<std::string, const Sprite*> sprites;
    std::unordered_map<std::string, const Color> colors;
public:
    Ressources() = default;
    Ressources(std::string ressources);
    void load(std::string);
    void free() const;
    const Model& getModel(const std::string& key) const { return  *models.at(key); }
    const SpriteSheet& getSpriteSheet(const std::string& key) const { return *spriteSheets.at(key); }
    Color& getColor(const std::string& key) const { return const_cast<Color &>(colors.at(key)); }
    const Sprite& getSprite(const std::string& key) const { return *sprites.at(key); }
    Terrain& getTerrain(const std::string& key) const { return const_cast<Terrain &>(terrains.at(key)); }
};