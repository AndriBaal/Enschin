#include "Vector3.h"

Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z){}

void Vector3::set(float x, float y, float z)
{
	this->x = x;
	this->y= y;
	this->z = z;
}