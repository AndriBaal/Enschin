#pragma once

#include <ostream>

/**
 * @brief Data structure that holds 2 integers.
 */
struct Vec2i {
    int x, y;

    Vec2i(int x = 0, int y = 0) : x(x), y(y) {};
    //Vec2i(b2Vec2 v) : x(v.x), y(v.y) {}

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
