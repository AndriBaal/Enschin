#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 2 floats.
 */
struct Vec2f {
    float x, y;
    static Vec2f nullVec2;

    Vec2f(float x = 0, float y = 0) : x(x), y(y) {};
    Vec2f(b2Vec2 v) : x(v.x), y(v.y) {}

    //Arithmetic
    Vec2f operator+(const Vec2f &v);
    Vec2f operator-(const Vec2f &v);
    Vec2f operator*(const Vec2f &v);
    Vec2f operator/(const Vec2f &v);

    //Assignment
    Vec2f &operator+=(const Vec2f &v);
    Vec2f &operator-=(const Vec2f &v);
    Vec2f &operator*=(const Vec2f &v);
    Vec2f &operator/=(const Vec2f &v);

    //other
    bool operator==(const Vec2f &v);
    bool operator!=(const Vec2f &v);
    Vec2f operator-();
};

std::ostream &operator<<(std::ostream &os, const Vec2f &v);
