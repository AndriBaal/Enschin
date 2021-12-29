#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 3 integer values.
 */
struct Vec3i {
    float x, y, z;

    Vec3i() = default;
    Vec3i(float x, float y, float z) : x(x), y(y), z(z) {}
    Vec3i(b2Vec3 v) : x(v.x), y(v.y), z(v.z) {}

    //Arithmetic
    Vec3i operator+(const Vec3i& v) const;
    Vec3i operator-(const Vec3i& v) const;
    Vec3i operator*(const Vec3i& v) const;
    Vec3i operator/(const Vec3i& v) const;

    Vec3i operator*(int i) const;
    Vec3i operator/(int i) const;

    //Assignment
    Vec3i& operator+=(const Vec3i& v);
    Vec3i& operator-=(const Vec3i& v);
    Vec3i& operator*=(const Vec3i& v);
    Vec3i& operator/=(const Vec3i& v);

    Vec3i& operator*=(int i);
    Vec3i& operator/=(int i);

    //other
    bool operator==(const Vec3i& v) const;
    bool operator!=(const Vec3i& v) const;

    Vec3i operator-() const;
};

std::ostream &operator<<(std::ostream &os, const Vec3i& v);
