#pragma once

#include "vec2i.h"
#include "texture.h"

struct SpriteSheet {
protected:
    Texture **textures;
private:
    unsigned short amountOfSprites = 0;
    unsigned char fps;
public:
    SpriteSheet() = default;
    SpriteSheet(const std::string &filePath, Vec2i spriteSize, unsigned char fps);
    ~SpriteSheet();

    Texture *getTexture(int index = 0) const { return textures[index]; }
    unsigned short getAmountOfSprites() { return amountOfSprites; }
    unsigned char getFps() { return fps; }
};