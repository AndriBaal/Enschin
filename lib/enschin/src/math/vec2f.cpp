#include <enschin/vec2f.h>

Vec2f Vec2f::nullVec2 = {0, 0};

//Arithmetic 
Vec2f Vec2f::operator+(const Vec2f& v) const {
	return {x + v.x, y + v.y};
}

Vec2f Vec2f::operator-(const Vec2f& v) const {
	return {x - v.x, y - v.y};
}

Vec2f Vec2f::operator*(const Vec2f& v) const {
	return {x * v.x, y * v.y};
}

Vec2f Vec2f::operator/(const Vec2f& v) const {
	return {x / v.x, y / v.y};
}

Vec2f Vec2f::operator*(float f) const {
    return {x * f, y * f};
}

Vec2f Vec2f::operator/(float f) const {
    return {x / f, y / f};
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

Vec2f& Vec2f::operator*=(float f) {
    x *= f;
    y *= f;
    return *this;
}

Vec2f& Vec2f::operator/=(float f) {
    x /= f;
    y /= f;
    return *this;
}


//Relational
bool Vec2f::operator==(const Vec2f& v) const {
	return x == v.x && y == v.y;
}

bool Vec2f::operator!=(const Vec2f& v) const {
	return !(x == v.x && y == v.y);
}

//Other
Vec2f Vec2f::operator-() const {
	return {-x, -y};
}

std::ostream& operator<<(std::ostream& os, const Vec2f& v) {
	os << "{" << v.x << ", " << v.y << "}";
	return os;
}
