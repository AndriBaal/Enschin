#include "Vectors.h"

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

Vector3::Vector3(float x, float y, float z)
{
	set(x, y, z);
}

void Vector3::set(float x, float y, float z)
{
	this->x = x;
	this->y= y;
	this->z = z;
}

Vector3 Vector3::operator=(Vector3& newVector)
{
	Vector3 v(newVector.x, newVector.y, newVector.z);
	return v;
}