#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 3 floating point values.
 */
struct Vec3 {
    float x, y, z;

    const static Vec3 nullVec3;
    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    Vec3(b2Vec3 v) : x(v.x), y(v.y), z(v.z) {}

    Vec3 operator+(const Vec3 &v);
    Vec3 operator-(const Vec3 &v);
    Vec3 operator*(const Vec3 &v);
    Vec3 operator/(const Vec3 &v);

    //Assignment
    Vec3 &operator+=(const Vec3 &v);
    Vec3 &operator-=(const Vec3 &v);
    Vec3 &operator*=(const Vec3 &v);
    Vec3 &operator/=(const Vec3 &v);

    //other
    bool operator==(const Vec3 &v);
    bool operator!=(const Vec3 &v);

    Vec3 operator-();
};

std::ostream &operator<<(std::ostream &os, const Vec3 &v);