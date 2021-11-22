#pragma once

#include "vec2.h"

/**
 * @brief 2D ray structure with a begin and an end vector.
 * 
 */
struct Ray2 {
    Vec2 v1, v2;

    Ray2(Vec2 v1, Vec2 v2);
};