#pragma once

#include <string>
#include <GL/glew.h>
#include "enschin/math/Dim2.h"
#include "../../dep/stb/stb_image.h"

/**
 * @brief Texture that can be drawn on a model
 */
class Texture {
private:
    unsigned int textureId;
    unsigned char* localBuffer;
    int BPP; //Bits per Pixel1

public:
    Texture(): textureId(0), localBuffer(nullptr), BPP(0) {}
    Texture(const std::string& path);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;
};