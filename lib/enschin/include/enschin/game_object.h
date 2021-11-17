#pragma once
#include "vec2.h"
#include "dim2.h"

class GameObject{
public:
	Vec2 pos;
	Vec2 dir;
    Dim2 dim;
    GameObject(Vec2 pos = {}, Dim2 dim = {}, Vec2 dir = {}): pos(pos), dim(dim), dir(dir) {}
};