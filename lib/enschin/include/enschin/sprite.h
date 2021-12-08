#pragma once

#include "sprite_sheet.h"

class Sprite : public SpriteSheet {
public:
    Sprite(const std::string &filePath);
};
