#pragma once
#include "vec2.h"
#include "dim2.h"
#include "ray2.h"

/**
 * @brief Physics namespace mostly used for collision detection.
 * 
 */
namespace Physics {
    bool isLineIntersecting(Ray2 a, Ray2 b);
}