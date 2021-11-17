#include "sprite.h"

Sprite::Sprite(const std::string& filePath) {
    textures = new Texture[1]{ Texture(filePath) };
}