#pragma once
#include "Vec2.h"
#include "Dim2.h"
#include "Ray2.hpp"

/**
 * @brief Physics namespace mostly used for collision detection.
 * 
 */
namespace Physics {
    bool isLineIntersecting(Ray2 a, Ray2 b);
}