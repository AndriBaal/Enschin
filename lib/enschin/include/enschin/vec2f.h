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
    Vec2f operator+(const Vec2f &v) const;
    Vec2f operator-(const Vec2f &v) const;
    Vec2f operator*(const Vec2f &v) const;
    Vec2f operator/(const Vec2f &v) const;

    Vec2f operator*(float f) const;

    //Assignment
    Vec2f& operator+=(const Vec2f& v);
    Vec2f& operator-=(const Vec2f& v);
    Vec2f& operator*=(const Vec2f& v);
    Vec2f& operator/=(const Vec2f& v);

    Vec2f& operator*=(float f);

    //other
    bool operator==(const Vec2f &v) const;
    bool operator!=(const Vec2f &v) const;
    Vec2f operator-() const;
};

std::ostream &operator<<(std::ostream &os, const Vec2f &v);
