#pragma once

#include "vec2f.h"

/**
 * @brief 2D ray structure with a begin and an end vector.
 * 
 */
struct Ray2 {
    Vec2f v1, v2;

    Ray2(Vec2f v1, Vec2f v2);
};