#include "vec4.h"


//Arithmetic 
Vec4 Vec4::operator+(const Vec4& v) {
    return Vec4(x + v.x, y + v.y, z + v.z, a + v.a);
}

Vec4 Vec4::operator-(const Vec4& v) {
    return Vec4(x - v.x, y - v.y, z - v.z, a - v.a);
}

Vec4 Vec4::operator*(const Vec4& v) {
    return Vec4(x * v.x, y * v.y, z * v.z, a * v.a);
}

Vec4 Vec4::operator/(const Vec4& v) {
    return Vec4(x / v.x, y / v.y, z / v.z, a / v.a);
}

Vec4 Vec4::operator%(const Vec4& v) {
    return Vec4(int(x) % int(v.x), int(y) % int(v.y), int(z) % int(v.z), int(a) & int(v.a));
}


Vec4 Vec4::operator+(float f) {
    return Vec4(x + f, y + f, z + f, a + f);
}

Vec4 Vec4::operator-(float f) {
    return Vec4(x - f, y - f, z - f, a - f);
}

Vec4 Vec4::operator*(float f) {
    return Vec4(x * f, y * f, z * f, a * f);
}

Vec4 Vec4::operator/(float f) {
    return Vec4(x / f, y / f, z / f, a / f);
}

Vec4 Vec4::operator%(int i) {
    return Vec4(int(x) % i, int(y) % i, int(z) % i, int(a) % i);
}

//Assignment
Vec4& Vec4::operator+=(const Vec4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    a += v.z;
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    a -= v.a;
    return *this;
}

Vec4& Vec4::operator*=(const Vec4& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    a *= v.a;
    return *this;
}

Vec4& Vec4::operator/=(const Vec4& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    a /= v.a;
    return *this;
}

Vec4& Vec4::operator%=(const Vec4& v) {
    x = int(x) % int(v.x);
    y = int(y) % int(v.y);
    z = int(z) % int(v.z);
    a = int(a) % int(v.a);
    return *this;
}


Vec4& Vec4::operator+=(float f) {
    x += f;
    y += f;
    z += f;
    a += f;
    return *this;
}

Vec4& Vec4::operator-=(float f) {
    x -= f;
    y -= f;
    z -= f;
    a -= f;
    return *this;
}

Vec4& Vec4::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    a *= f;
    return *this;
}

Vec4& Vec4::operator/=(float f) {
    x /= f;
    y /= f;
    z /= f;
    a /= f;
    return *this;
}

Vec4& Vec4::operator%=(int i) {
    x = int(x) % i;
    y = int(y) % i;
    z = int(y) % i;
    a = int(a) % i;
    return *this;
}

Vec4& Vec4::operator++(int i) {
    x+=1.0f;
    y+=1.0f;
    z+=1.0f;
    a+=1.0f;
    return *this;
}

Vec4& Vec4::operator--(int i) {
    x-=1.0f;
    y-=1.0f;
    z-=1.0f;
    a-=1.0f;
    return *this;
}

//Relational
bool Vec4::operator==(const Vec4& v) {
    return x == v.x && y == v.y && z == v.z && a == v.a;
}

bool Vec4::operator!=(const Vec4& v) {
    return !(x == v.x && y == v.y && z == v.z && a == v.a);
}

bool Vec4::operator>=(const Vec4& v) {
    return x >= v.x && y >= v.y && z >= v.z && a >= v.a;
}

bool Vec4::operator<=(const Vec4& v) {
    return x <= v.x && y <= v.y && z <= v.z && a <= v.a;
}

bool Vec4::operator>(const Vec4& v) {
    return x > v.x && y > v.y && z > v.z && a > v.z;
}

bool Vec4::operator<(const Vec4& v) {
    return x < v.x && y < v.y && z < v.z && a < v.z;
}


//Other
Vec4 Vec4::operator-() {
    return Vec4(-x, -y, -z, -a);
}

std::ostream& operator<<(std::ostream& os, const Vec4& v) {
    os << "{" << v.x << ", " << v.y << ", " << v.z << ", " << v.a << "}";
    return os;
}