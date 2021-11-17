#pragma once
#include "vec2.h"
#include "color.h"

/**
 * @brief Light with a Color, Radius (strength) and Position
 * 
 */
struct Light {
private:
    float radius;
    Color lightColor;
    Vec2 pos;
public:
    void setRadius(float newRadius) { this->radius = newRadius; }
    float getRadius() { return radius; }
    void setLightColor(const Color& newColor) { this->lightColor = newColor; }
    Color getLightColor() { return lightColor; }
    void setPos(Vec2 newPos) { this->pos = newPos; }
    Vec2 getPos() { return pos; }
};