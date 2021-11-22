#pragma once
#include "vec2.h"

class GameObject{
public:
	Vec2 pos;
	Vec2 dir;
    Vec2 dim;
    GameObject(Vec2 pos = {}, Vec2 dim = {}, Vec2 dir = {}): pos(pos), dim(dim), dir(dir) {}
};