#include <iostream>
#include "sprite_sheet.h"

SpriteSheet::SpriteSheet(const std::string& filePath, Dim2 spriteSize, unsigned char fps) {
    stbi_set_flip_vertically_on_load(true);
    int width, height, BPP;
    unsigned char* localBuffer = nullptr;
    localBuffer = stbi_load(filePath.c_str(), &width, &height, &BPP, 4);

    textures = new Texture[int(height / spriteSize.h * (width / spriteSize.w))];
    std::cout << "Size of textures" << height / spriteSize.h * (width / spriteSize.w) << std::endl;

    glPixelStorei(GL_UNPACK_ROW_LENGTH, width);
    for (int y = 0; y< height; y += spriteSize.h) {
        for (int x = 0; x < width; x += spriteSize.w) {
            char *subimg = (char*)localBuffer + (y + x*width)*4;
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, spriteSize.w, spriteSize.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, subimg);
            textures[y*x] = Texture(subimg, spriteSize.w, spriteSize.h);
            delete subimg;
        }
    }
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
}

SpriteSheet::SpriteSheet(const std::string &filePath) {
    textures = new Texture[1];
    textures[0] = Texture(filePath);
}

void SpriteSheet::free() {
    for (int i = 0; i< amountOfSprites; i ++)
        textures[i].free();
    delete(textures);
}

