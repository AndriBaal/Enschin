#include <enschin/vec3i.h>

//Arithmetic
Vec3i Vec3i::operator+(const Vec3i& v) {
    return Vec3i(x + v.x, y + v.y, z + v.z);
}

Vec3i Vec3i::operator-(const Vec3i& v) {
    return Vec3i(x - v.x, y - v.y, z - v.z);
}

Vec3i Vec3i::operator*(const Vec3i& v) {
    return Vec3i(x * v.x, y * v.y, z * v.z);
}

Vec3i Vec3i::operator/(const Vec3i& v) {
    return Vec3i(x / v.x, y / v.y, z / v.z);
}


//Assignment
Vec3i& Vec3i::operator+=(const Vec3i& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec3i& Vec3i::operator-=(const Vec3i& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec3i& Vec3i::operator*=(const Vec3i& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vec3i& Vec3i::operator/=(const Vec3i& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

//Relational
bool Vec3i::operator==(const Vec3i& v) {
    return x == v.x && y == v.y && z == v.z;
}

bool Vec3i::operator!=(const Vec3i& v) {
    return !(x == v.x && y == v.y && z == v.z);
}


//Other
Vec3i Vec3i::operator-() {
    return Vec3i(-x, -y, -z);
}

std::ostream& operator<<(std::ostream& os, const Vec3i& v) {
    os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    return os;
}

