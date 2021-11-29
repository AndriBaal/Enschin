#include <iostream>
#include <enschin/sprite_sheet.h>

SpriteSheet::SpriteSheet(const std::string& filePath, Vec2 spriteSize, unsigned char fps) : fps(fps) {
    stbi_set_flip_vertically_on_load(true);
    int width, height, BPP;
    unsigned char* localBuffer = nullptr;
    localBuffer = stbi_load(filePath.c_str(), &width, &height, &BPP, 4);

    textures = new Texture*[int(height / spriteSize.y * (width / spriteSize.x))];

    glPixelStorei(GL_UNPACK_ROW_LENGTH, width);
    for (int y = 0; y< height; y += spriteSize.y) {
        for (int x = 0; x < width; x += spriteSize.x) {
            const unsigned char* subimg = localBuffer + (y + x)*4;
            textures[amountOfSprites] = new Texture(subimg, spriteSize.x, spriteSize.y);
            amountOfSprites++;
        }
    }
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    if (localBuffer) stbi_image_free(localBuffer);
}

SpriteSheet::~SpriteSheet() {
    for (int i = 0; i< amountOfSprites; i ++)
        delete textures[i];
    delete []textures;
}

