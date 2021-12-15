#include <include/enschin/vec3f.h>

const Vec3 Vec3::nullVec3 = {0, 0, 0};

//Arithmetic 
Vec3 Vec3::operator+(const Vec3& v) {
	return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) {
	return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator*(const Vec3& v) {
	return Vec3(x * v.x, y * v.y, z * v.z);
}

Vec3 Vec3::operator/(const Vec3& v) {
	return Vec3(x / v.x, y / v.y, z / v.z);
}


//Assignment
Vec3& Vec3::operator+=(const Vec3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& v) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& v) {
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

//Relational
bool Vec3::operator==(const Vec3& v) {
	return x == v.x && y == v.y && z == v.z;
}

bool Vec3::operator!=(const Vec3& v) {
	return !(x == v.x && y == v.y && z == v.z);
}


//Other
Vec3 Vec3::operator-() {
	return Vec3(-x, -y, -z);
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
	os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
	return os;
}