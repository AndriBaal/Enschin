#include <enschin/vec2f.h>

Vec2f Vec2f::nullVec2 = {0, 0};

//Arithmetic 
Vec2f Vec2f::operator+(const Vec2f& v) {
	return Vec2f(x + v.x, y + v.y);
}

Vec2f Vec2f::operator-(const Vec2f& v) {
	return Vec2f(x - v.x, y - v.y);
}

Vec2f Vec2f::operator*(const Vec2f& v) {
	return Vec2f(x * v.x, y * v.y);
}

Vec2f Vec2f::operator/(const Vec2f& v) {
	return Vec2f(x / v.x, y / v.y);
}


//Assignment
Vec2f& Vec2f::operator+=(const Vec2f& v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vec2f& Vec2f::operator-=(const Vec2f& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2f& Vec2f::operator*=(const Vec2f& v) {
	x *= v.x;
	y *= v.y;
	return *this;
}

Vec2f& Vec2f::operator/=(const Vec2f& v) {
	x /= v.x;
	y /= v.y;
	return *this;
}


//Relational
bool Vec2f::operator==(const Vec2f& v) {
	return x == v.x && y == v.y;
}

bool Vec2f::operator!=(const Vec2f& v) {
	return !(x == v.x && y == v.y);
}

//Other
Vec2f Vec2f::operator-() {
	return Vec2f(-x, -y);
}

std::ostream& operator<<(std::ostream& os, const Vec2f& v) {
	os << "{" << v.x << ", " << v.y << "}";
	return os;
}
