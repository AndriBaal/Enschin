#pragma once

#include "vec2f.h"
#include "color.h"

/**
 * @brief Light with a Color, Radius (strength) and Position
 * 
 */
struct Light {
private:
    float radius;
    Color lightColor;
    Vec2f pos;
public:
    void setRadius(float newRadius) { this->radius = newRadius; }

    float getRadius() { return radius; }

    void setLightColor(const Color &newColor) { this->lightColor = newColor; }

    Color getLightColor() { return lightColor; }

    void setPos(Vec2f newPos) { this->pos = newPos; }

    Vec2f getPos() { return pos; }
};