#pragma once
#include "enschin/math/dim2.h"

struct SpriteSheet() {
private:
    const Texture* textures;
    unsigned short amountOfSprites;
public:
    SpriteSheet(const char* filePath, Dim2 spriteSize, unsigned short amountOfSprites);
    void free();
};