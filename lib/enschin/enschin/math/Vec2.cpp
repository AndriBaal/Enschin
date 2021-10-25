#include "Vec2.h"

Vec2::Vec2(float x, float y) : x(x), y(y){}

Vec2 Vec2::operator=(const Vec2& newVector) {
	x = newVector.x;
	y = newVector.y;
	return *this;
}

Vec2 Vec2::operator+(const Vec2& otherVector) {
	return Vec2(x + otherVector.x, y + otherVector.y);
}

Vec2 Vec2::operator-(const Vec2& otherVector) {
	return Vec2(x - otherVector.x, y - otherVector.y);
}

Vec2 Vec2::operator-() {
	return Vec2(-x, -y);
}

void Vec2::set(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vec2::set(Vec2 v) {
	this->x = v.x;
	this->y = v.y;
}

float Vec2::getRatioXY() {
	return y / x;
}

float Vec2::getRatioYX(){
	return x / y;
}