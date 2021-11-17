#include <enschin/vec2.h>

//Arithmetic 
Vec2 Vec2::operator+(const Vec2& v) {
	return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(const Vec2& v) {
	return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator*(const Vec2& v) {
	return Vec2(x * v.x, y * v.y);
}

Vec2 Vec2::operator/(const Vec2& v) {
	return Vec2(x / v.x, y / v.y);
}

Vec2 Vec2::operator%(const Vec2& v) {
	return Vec2(int(x) % int(v.x), int(y) % int(v.y));
}


Vec2 Vec2::operator+(float f) {
	return Vec2(x + f, y + f);
}

Vec2 Vec2::operator-(float f) {
	return Vec2(x - f, y - f);
}

Vec2 Vec2::operator*(float f) {
	return Vec2(x * f, y * f);
}

Vec2 Vec2::operator/(float f) {
	return Vec2(x / f, y / f);
}

Vec2 Vec2::operator%(int i) {
	return Vec2(int(x) % i, int(y) % i);
}

//Assignment
Vec2& Vec2::operator+=(const Vec2& v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2& Vec2::operator*=(const Vec2& v) {
	x *= v.x;
	y *= v.y;
	return *this;
}

Vec2& Vec2::operator/=(const Vec2& v) {
	x /= v.x;
	y /= v.y;
	return *this;
}

Vec2& Vec2::operator%=(const Vec2& v) {
	x = int(x) % int(v.x);
	y = int(y) % int(v.y);
	return *this;
}


Vec2& Vec2::operator+=(float f) {
	x += f;
	y += f;
	return *this;
}

Vec2& Vec2::operator-=(float f) {
	x -= f;
	y -= f;
	return *this;
}

Vec2& Vec2::operator*=(float f) {
	x *= f;
	y *= f;
	return *this;
}

Vec2& Vec2::operator/=(float f) {
	x /= f;
	y /= f;
	return *this;
}

Vec2& Vec2::operator%=(int i) {
	x = int(x) % i;
	y = int(y) % i;
	return *this;
}

Vec2& Vec2::operator++(int i) {
	x+=1.0f;
	y+=1.0f;
	return *this;
}

Vec2& Vec2::operator--(int i) {
	x-=1.0f;
	y-=1.0f;
	return *this;
}

//Relational
bool Vec2::operator==(const Vec2& v) {
	return x == v.x && y == v.y;
}

bool Vec2::operator!=(const Vec2& v) {
	return !(x == v.x && y == v.y);
}

bool Vec2::operator>=(const Vec2& v) {
	return x >= v.x && y >= v.y;
}

bool Vec2::operator<=(const Vec2& v) {
	return x <= v.x && y <= v.y;
}

bool Vec2::operator>(const Vec2& v) {
	return x > v.x && y > v.y;
}

bool Vec2::operator<(const Vec2& v) {
	return x < v.x && y < v.y;
}


//Other
Vec2 Vec2::operator-() {
	return Vec2(-x, -y);
}

std::ostream& operator<<(std::ostream& os, const Vec2& v) {
	os << "{" << v.x << ", " << v.y << "}";
	return os;
}
