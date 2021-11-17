#pragma once
#include "dim2.h"
#include "texture.h"

struct SpriteSheet {
protected:
    Texture* textures;
private:
    unsigned short amountOfSprites = 0;
    unsigned char fps;
public:
    SpriteSheet() = default;
    SpriteSheet(const std::string& filePath, Dim2 spriteSize, unsigned char fps);

    Texture& getCurrentSprite(unsigned int sprite = 0);
    Texture& getTexture(int index = 0){ return textures[index]; }
    unsigned short getAmountOfSprites(){ return amountOfSprites; }
    unsigned char getFps(){ return fps; }
    void free();
};