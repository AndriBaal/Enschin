#include <include/enschin/vec3f.h>

const Vec3f Vec3f::nullVec3 = {0, 0, 0};

//Arithmetic 
Vec3f Vec3f::operator+(const Vec3f& v) const {
	return {x + v.x, y + v.y, z + v.z};
}

Vec3f Vec3f::operator-(const Vec3f& v) const {
	return {x - v.x, y - v.y, z - v.z};
}

Vec3f Vec3f::operator*(const Vec3f& v) const {
	return {x * v.x, y * v.y, z * v.z};
}

Vec3f Vec3f::operator/(const Vec3f& v) const {
	return {x / v.x, y / v.y, z / v.z};
}

Vec3f Vec3f::operator*(float f) const {
    return {x * f, y * f, z * f};
}


//Assignment
Vec3f& Vec3f::operator+=(const Vec3f& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vec3f& Vec3f::operator-=(const Vec3f& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vec3f& Vec3f::operator*=(const Vec3f& v) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

Vec3f& Vec3f::operator/=(const Vec3f& v) {
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

Vec3f& Vec3f::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

//Relational
bool Vec3f::operator==(const Vec3f& v) const {
	return x == v.x && y == v.y && z == v.z;
}

bool Vec3f::operator!=(const Vec3f& v) const {
	return !(x == v.x && y == v.y && z == v.z);
}


//Other
Vec3f Vec3f::operator-() const {
	return {-x, -y, -z};
}

std::ostream& operator<<(std::ostream& os, const Vec3f& v) {
	os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
	return os;
}