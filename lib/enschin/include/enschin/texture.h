#pragma once

#include <iostream>
#include <GL/glew.h>
#include "vec2f.h"
#include "../deps/stb/stb_image.h"

/**
 * @brief Texture that can be drawn on a model
 */
class Texture {
private:
    unsigned int textureId;
public:
    Texture() = default;
    Texture(unsigned const char *pixelBuffer, unsigned short pixelsW, unsigned short pixelsH);
    Texture(const std::string &path);
    ~Texture();
    void bind(unsigned int slot = 0) const;
    void unbind() const;
};