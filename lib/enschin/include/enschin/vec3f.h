#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 3 floating point values.
 */
struct Vec3f {
    float x, y, z;

    const static Vec3f nullVec3;
    Vec3f(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    Vec3f(b2Vec3 v) : x(v.x), y(v.y), z(v.z) {}

    Vec3f operator+(const Vec3f &v);
    Vec3f operator-(const Vec3f &v);
    Vec3f operator*(const Vec3f &v);
    Vec3f operator/(const Vec3f &v);

    //Assignment
    Vec3f &operator+=(const Vec3f &v);
    Vec3f &operator-=(const Vec3f &v);
    Vec3f &operator*=(const Vec3f &v);
    Vec3f &operator/=(const Vec3f &v);

    //other
    bool operator==(const Vec3f &v);
    bool operator!=(const Vec3f &v);

    Vec3f operator-();
};

std::ostream &operator<<(std::ostream &os, const Vec3f &v);