#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 2 floats.
 */
struct Vec2i {
    int x, y;
    static Vec2i nullVec2;

    Vec2i(int x = 0, int y = 0) : x(x), y(y) {};
    Vec2i(b2Vec2 v) : x(v.x), y(v.y) {}

    //Arithmetic
    Vec2i operator+(const Vec2i &v);
    Vec2i operator-(const Vec2i &v);
    Vec2i operator*(const Vec2i &v);
    Vec2i operator/(const Vec2i &v);

    //Assignment
    Vec2i &operator+=(const Vec2i &v);
    Vec2i &operator-=(const Vec2i &v);
    Vec2i &operator*=(const Vec2i &v);
    Vec2i &operator/=(const Vec2i &v);

    //other
    bool operator==(const Vec2i &v);
    bool operator!=(const Vec2i &v);
    Vec2i operator-();
};

std::ostream &operator<<(std::ostream &os, const Vec2i &v);
