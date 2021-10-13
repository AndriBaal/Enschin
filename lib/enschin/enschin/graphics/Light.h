#pragma once
#include "../math/Vectors.h"
#include "Color.hpp"

class Light{
private:
    float radius;
    Color lightColor;
    Vector2 pos;
public:

    void setRadius(float newRadius){ this->radius = newRadius; }
    float getRadius() { return radius; }
    void setLightColor(Color newColor){ this->lightColor = newColor; }
    Color getLightColor(){ return lightColor; }
    void setPos(Vector2 newPos){ this->pos = newPos; }
    Vector2 getPos(){ return pos; }
};