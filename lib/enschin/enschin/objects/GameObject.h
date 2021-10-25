#pragma once
#include "../math/Vec2.h"
#include "../math/Dim.h"

class GameObject{
public:
	Vec2 pos;
	Vec2 dir;
    Dim dim;
    GameObject(Vec2 pos = {}, Dim dim = {}, Vec2 dir = {}): pos(pos), dim(dim), dir(dir) {}
};