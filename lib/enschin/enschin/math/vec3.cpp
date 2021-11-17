#include "vec3.h"


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

Vec3 Vec3::operator%(const Vec3& v) {
	return Vec3(int(x) % int(v.x), int(y) % int(v.y), int(z) % int(v.z));
}


Vec3 Vec3::operator+(float f) {
	return Vec3(x + f, y + f, z + f);
}

Vec3 Vec3::operator-(float f) {
	return Vec3(x - f, y - f, z - f);
}

Vec3 Vec3::operator*(float f) {
	return Vec3(x * f, y * f, z * f);
}

Vec3 Vec3::operator/(float f) {
	return Vec3(x / f, y / f, z / f);
}

Vec3 Vec3::operator%(int i) {
	return Vec3(int(x) % i, int(y) % i, int(z) % i);
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

Vec3& Vec3::operator%=(const Vec3& v) {
	x = int(x) % int(v.x);
	y = int(y) % int(v.y);
	z = int(z) % int(v.z);
	return *this;
}


Vec3& Vec3::operator+=(float f) {
	x += f;
	y += f;
	z += f;
	return *this;
}

Vec3& Vec3::operator-=(float f) {
	x -= f;
	y -= f;
	z -= f;
	return *this;
}

Vec3& Vec3::operator*=(float f) {
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

Vec3& Vec3::operator/=(float f) {
	x /= f;
	y /= f;
	z /= f;
	return *this;
}

Vec3& Vec3::operator%=(int i) {
	x = int(x) % i;
	y = int(y) % i;
	z = int(y) % i;
	return *this;
}

Vec3& Vec3::operator++(int i) {
	x+=1.0f;
	y+=1.0f;
	z+=1.0f;
	return *this;
}

Vec3& Vec3::operator--(int i) {
	x-=1.0f;
	y-=1.0f;
	z-=1.0f;
	return *this;
}

//Relational
bool Vec3::operator==(const Vec3& v) {
	return x == v.x && y == v.y && z == v.z;
}

bool Vec3::operator!=(const Vec3& v) {
	return !(x == v.x && y == v.y && z == v.z);
}

bool Vec3::operator>=(const Vec3& v) {
	return x >= v.x && y >= v.y && z >= v.z;
}

bool Vec3::operator<=(const Vec3& v) {
	return x <= v.x && y <= v.y && z <= v.z;
}

bool Vec3::operator>(const Vec3& v) {
	return x > v.x && y > v.y && z > v.z;
}

bool Vec3::operator<(const Vec3& v) {
	return x < v.x && y < v.y && z < v.z;
}


//Other
Vec3 Vec3::operator-() {
	return Vec3(-x, -y, -z);
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
	os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
	return os;
}