#pragma once
#include "../math/Vector2.h"
#include "../math/Dimension.h"

class GameObject{
private:

public:
	Vector2 pos;
	Vector2 dir;
    Dimension dim;
    GameObject(Vector2 pos = {}, Dimension dim = {}, Vector2 dir = {}): pos(pos), dim(dim), dir(dir) {}
};