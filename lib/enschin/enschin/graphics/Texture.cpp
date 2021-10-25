#include "Texture.h"


Texture::Texture(const std::string& path)
    : textureId(0), localBuffer(nullptr), BPP(0), size{} {
    stbi_set_flip_vertically_on_load(1);
    int width;
    int height;
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

Texture::~Texture() {
    glDeleteTextures(1, &textureId);
}

void Texture::bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}