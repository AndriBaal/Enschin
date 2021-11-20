#pragma once
#include <ostream>

/**
 * @brief Data structure that holds 4 floating point values.
 */
struct Vec4 {
    float x, y, z, a;
    Vec4(float x = 0, float y = 0, float z = 0, float a = 0) : x(x), y(y), z(z), a(a){}

    Vec4 operator+(const Vec4& v);
    Vec4 operator-(const Vec4& v);
    Vec4 operator*(const Vec4& v);
    Vec4 operator/(const Vec4& v);
    Vec4 operator%(const Vec4& v);

    Vec4 operator+(float f);
    Vec4 operator-(float f);
    Vec4 operator*(float f);
    Vec4 operator/(float f);
    Vec4 operator%(int i);

    //Assignment
    Vec4& operator+=(const Vec4& v);
    Vec4& operator-=(const Vec4& v);
    Vec4& operator*=(const Vec4& v);
    Vec4& operator/=(const Vec4& v);
    Vec4& operator%=(const Vec4& v);

    Vec4& operator+=(float f);
    Vec4& operator-=(float f);
    Vec4& operator*=(float f);
    Vec4& operator/=(float f);
    Vec4& operator%=(int i);

    Vec4& operator++(int i);
    Vec4& operator--(int i);

    //other
    bool operator==(const Vec4& v);
    bool operator!=(const Vec4& v);
    bool operator>=(const Vec4& v);
    bool operator<=(const Vec4& v);
    bool operator<(const Vec4& v);
    bool operator>(const Vec4& v);

    Vec4 operator-();
};

std::ostream& operator<<(std::ostream& os, const Vec4& v);