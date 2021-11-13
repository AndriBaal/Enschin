#pragma once

#include <string>
#include <GL/glew.h>
#include "enschin/math/dim2.h"
#include "../../dep/stb/stb_image.h"
#include "../../dep/stb/stb_image_resize.h"

/**
 * @brief Texture that can be drawn on a model
 */
class Texture {
private:
    unsigned int textureId;
    static unsigned int boundTexture;
public:
    Texture(const std::string& path);
    void free();

    void bind(unsigned int slot = 0) const;
    void unbind() const;
};