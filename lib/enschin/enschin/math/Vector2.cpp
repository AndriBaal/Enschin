#include "Vector2.h"

Vector2::Vector2(float x, float y) : x(x), y(y){}

Vector2 Vector2::operator=(const Vector2& newVector)
{
	x = newVector.x;
	y = newVector.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& otherVector)
{
	return Vector2(x + otherVector.x, y + otherVector.y);
}

Vector2 Vector2::operator-(const Vector2& otherVector)
{
	return Vector2(x - otherVector.x, y - otherVector.y);
}

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

void Vector2::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::set(Vector2 v)
{
	this->x = v.x;
	this->y = v.y;
}

float Vector2::getRatioXY()
{
	return y / x;
}

float Vector2::getRatioYX(){
	return x / y;
}