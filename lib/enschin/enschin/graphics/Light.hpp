#pragma once
#include "../math/Vec2.h"
#include "Color.hpp"

struct Light{
private:
    float radius;
    Color lightColor;
    Vec2 pos;
public:

    void setRadius(float newRadius){ this->radius = newRadius; }
    float getRadius() { return radius; }
    void setLightColor(Color newColor){ this->lightColor = newColor; }
    Color getLightColor(){ return lightColor; }
    void setPos(Vec2 newPos){ this->pos = newPos; }
    Vec2 getPos(){ return pos; }
};