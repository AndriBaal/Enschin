#pragma once

#include "Vector2.h"

struct Ray
{
    Vector2 v1, v2;
    Ray(Vector2 v1, Vector2 v2) : v1(v1), v2(v2){}

};