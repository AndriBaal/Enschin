#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 2 floats.
 */
struct Vec2 {
    float x, y;

    Vec2(float x = 0, float y = 0) : x(x), y(y) {};

    Vec2(b2Vec2 v) : x(v.x), y(v.y) {}

    b2Vec2 toB2() const { return {x, y}; }

    static Vec2 nullVec2;

    //Arithmetic
    Vec2 operator+(const Vec2 &v);

    Vec2 operator-(const Vec2 &v);

    Vec2 operator*(const Vec2 &v);

    Vec2 operator/(const Vec2 &v);

    Vec2 operator%(const Vec2 &v);

    Vec2 operator+(float f);

    Vec2 operator-(float f);

    Vec2 operator*(float f);

    Vec2 operator/(float f);

    Vec2 operator%(int i);

    //Assignment
    Vec2 &operator+=(const Vec2 &v);

    Vec2 &operator-=(const Vec2 &v);

    Vec2 &operator*=(const Vec2 &v);

    Vec2 &operator/=(const Vec2 &v);

    Vec2 &operator%=(const Vec2 &v);

    Vec2 &operator+=(float f);

    Vec2 &operator-=(float f);

    Vec2 &operator*=(float f);

    Vec2 &operator/=(float f);

    Vec2 &operator%=(int i);

    Vec2 &operator++(int i);

    Vec2 &operator--(int i);

    //other
    bool operator==(const Vec2 &v);

    bool operator!=(const Vec2 &v);

    bool operator>=(const Vec2 &v);

    bool operator<=(const Vec2 &v);

    bool operator<(const Vec2 &v);

    bool operator>(const Vec2 &v);

    Vec2 operator-();
};

std::ostream &operator<<(std::ostream &os, const Vec2 &v);
