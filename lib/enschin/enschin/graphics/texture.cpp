#include <iostream>
#include "texture.h"

unsigned int Texture::boundTexture = 0;




/**
 * @brief Construct a new Texture object and create an id on the GPU
 * 
 * @param path Image path
 */
Texture::Texture(const std::string& path)
    : textureId(0) {
    stbi_set_flip_vertically_on_load(1);
    int width, height, BPP;
    unsigned char* localBuffer = nullptr;
    localBuffer = stbi_load(path.c_str(), &width, &height, &BPP, 4);


    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId); // Bind without slot selection

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
    unbind();

    if (localBuffer) stbi_image_free(localBuffer);
};

/**
 * @brief Destroy the Texture object and delete the Texture from the GPU
 */
void Texture::free() {
    glDeleteTextures(1, &textureId);
}

/**
 * @brief Bind the Texture
 * 
 * @param slot Slot for the texture
 */
void Texture::bind(unsigned int slot) const {
    if (boundTexture != textureId) {
        boundTexture = textureId;
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
}

/**
 * @brief Unbind the Texture
 */
void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}