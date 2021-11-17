#include <iostream>
#include "sprite_sheet.h"

SpriteSheet::SpriteSheet(const std::string& filePath, Dim2 spriteSize, unsigned char fps) : fps(fps) {
    stbi_set_flip_vertically_on_load(true);
    int width, height, BPP;
    unsigned char* localBuffer = nullptr;
    localBuffer = stbi_load(filePath.c_str(), &width, &height, &BPP, 4);

    textures = new Texture[int(height / spriteSize.h * (width / spriteSize.w))];

    glPixelStorei(GL_UNPACK_ROW_LENGTH, width);
    for (int y = 0; y< height; y += spriteSize.h) {
        for (int x = 0; x < width; x += spriteSize.w) {
            const unsigned char* subimg = localBuffer + (y + x)*4;
            textures[amountOfSprites] = Texture(subimg, spriteSize.w, spriteSize.h);
            amountOfSprites++;
        }
    }
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    if (localBuffer) stbi_image_free(localBuffer);
}

void SpriteSheet::free() {
    for (int i = 0; i< amountOfSprites; i ++)
        textures[i].free();
    delete(textures);
}

