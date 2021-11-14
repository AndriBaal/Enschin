#pragma once
#include "enschin/math/dim2.h"
#include "enschin/graphics/texture.h"

struct SpriteSheet {
protected:
    Texture* textures;
private:
    unsigned short amountOfSprites;
    unsigned char fps;
public:
    SpriteSheet() = default;
    SpriteSheet(const std::string& filePath, Dim2 spriteSize, unsigned char fps);
    SpriteSheet(const std::string& filePath);

    Texture& getCurrentSprite(unsigned int sprite = 0);
    Texture& getTexture(int index = 0){ return textures[index]; }
    void free();
};