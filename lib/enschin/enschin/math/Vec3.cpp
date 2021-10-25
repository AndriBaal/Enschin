#include "Vec3.h"

Vec3::Vec3(float x, float y, float z): x(x), y(y), z(z){}

void Vec3::set(float x, float y, float z) {
	this->x = x;
	this->y= y;
	this->z = z;
}