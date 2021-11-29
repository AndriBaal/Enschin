#include <enschin/sprite.h>

Sprite::Sprite(const std::string& filePath) {
    textures = new Texture*[1]{ new Texture(filePath) };
}