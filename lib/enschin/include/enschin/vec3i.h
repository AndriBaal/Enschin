#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 3 integer values.
 */
struct Vec3i {
    float x, y, z;

    const static Vec3i nullVec3i;
    Vec3i(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    Vec3i(b2Vec3 v) : x(v.x), y(v.y), z(v.z) {}

    Vec3i operator+(const Vec3i &v);
    Vec3i operator-(const Vec3i &v);
    Vec3i operator*(const Vec3i &v);
    Vec3i operator/(const Vec3i &v);

    //Assignment
    Vec3i &operator+=(const Vec3i &v);
    Vec3i &operator-=(const Vec3i &v);
    Vec3i &operator*=(const Vec3i &v);
    Vec3i &operator/=(const Vec3i &v);

    //other
    bool operator==(const Vec3i &v);
    bool operator!=(const Vec3i &v);

    Vec3i operator-();
};

std::ostream &operator<<(std::ostream &os, const Vec3i &v);
