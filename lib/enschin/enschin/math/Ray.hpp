#pragma once

#include "Vec2.h"

struct Ray {
    Vec2 v1, v2;
    Ray(Vec2 v1, Vec2 v2) : v1(v1), v2(v2){}

};