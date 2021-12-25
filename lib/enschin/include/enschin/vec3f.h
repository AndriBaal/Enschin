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

    //Arithmetic
    Vec3f operator+(const Vec3f& v) const;
    Vec3f operator-(const Vec3f& v) const;
    Vec3f operator*(const Vec3f& v) const;
    Vec3f operator/(const Vec3f& v) const;

    Vec3f operator*(float f) const;

    //Assignment
    Vec3f& operator+=(const Vec3f& v);
    Vec3f& operator-=(const Vec3f& v);
    Vec3f& operator*=(const Vec3f& v);
    Vec3f& operator/=(const Vec3f& v);

    Vec3f& operator*=(float f);

    //other
    bool operator==(const Vec3f& v) const;
    bool operator!=(const Vec3f& v) const;

    Vec3f operator-() const;
};

std::ostream &operator<<(std::ostream &os, const Vec3f& v);