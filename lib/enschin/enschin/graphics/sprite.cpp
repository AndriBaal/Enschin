#include "sprite.h"

Sprite::Sprite(const std::string& filePath) {
    textures = new Texture[1];
    textures[0] = Texture(filePath);
}