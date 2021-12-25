#include <enschin/vec3i.h>

//Arithmetic
Vec3i Vec3i::operator+(const Vec3i& v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vec3i Vec3i::operator-(const Vec3i& v) const {
    return {x - v.x, y - v.y, z - v.z};
}

Vec3i Vec3i::operator*(const Vec3i& v) const {
    return {x * v.x, y * v.y, z * v.z};
}

Vec3i Vec3i::operator/(const Vec3i& v) const {
    return {x / v.x, y / v.y, z / v.z};
}

Vec3i Vec3i::operator*(int i) const {
    return {x * i, y * i, z * i};
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

Vec3i& Vec3i::operator*=(int i) {
    x *= i;
    y *= i;
    z *= i;
    return *this;
}

//Relational
bool Vec3i::operator==(const Vec3i& v) const {
    return x == v.x && y == v.y && z == v.z;
}

bool Vec3i::operator!=(const Vec3i& v) const {
    return !(x == v.x && y == v.y && z == v.z);
}


//Other
Vec3i Vec3i::operator-() const {
    return {-x, -y, -z};
}

std::ostream& operator<<(std::ostream& os, const Vec3i& v) {
    os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    return os;
}

