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
    Vec2i operator+(const Vec2i& v) const;
    Vec2i operator-(const Vec2i& v) const;
    Vec2i operator*(const Vec2i& v) const;
    Vec2i operator/(const Vec2i& v) const;

    Vec2i operator*(int i) const;

    //Assignment
    Vec2i& operator+=(const Vec2i& v);
    Vec2i& operator-=(const Vec2i& v);
    Vec2i& operator*=(const Vec2i& v);
    Vec2i& operator/=(const Vec2i& v);

    Vec2i& operator*=(int i);

    //other
    bool operator==(const Vec2i& v) const;
    bool operator!=(const Vec2i& v) const;
    Vec2i operator-() const;
};

std::ostream &operator<<(std::ostream &os, const Vec2i& v);
