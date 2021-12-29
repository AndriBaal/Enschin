#pragma once

#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 3 floating point values.
 */
struct Vec3f {
    float x, y, z;

    Vec3f() = default;
    Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}
    Vec3f(b2Vec3 v) : x(v.x), y(v.y), z(v.z) {}

    //Arithmetic
    Vec3f operator+(const Vec3f& v) const;
    Vec3f operator-(const Vec3f& v) const;
    Vec3f operator*(const Vec3f& v) const;
    Vec3f operator/(const Vec3f& v) const;

    Vec3f operator*(float f) const;
    Vec3f operator/(float f) const;

    //Assignment
    Vec3f& operator+=(const Vec3f& v);
    Vec3f& operator-=(const Vec3f& v);
    Vec3f& operator*=(const Vec3f& v);
    Vec3f& operator/=(const Vec3f& v);

    Vec3f& operator*=(float f);
    Vec3f& operator/=(float f);

    //other
    bool operator==(const Vec3f& v) const;
    bool operator!=(const Vec3f& v) const;

    Vec3f operator-() const;
};

std::ostream &operator<<(std::ostream &os, const Vec3f& v);