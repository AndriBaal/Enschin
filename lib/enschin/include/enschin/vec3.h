#pragma once
#include <ostream>
#include <box2d/b2_math.h>

/**
 * @brief Data structure that holds 3 floating point values.
 */
struct Vec3 {
	float x, y, z;
	Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z){}

    const static Vec3 nullVec3;

    b2Vec3 toBox(){ return b2Vec3(x, y, z); }

    Vec3 operator+(const Vec3& v);
	Vec3 operator-(const Vec3& v);
	Vec3 operator*(const Vec3& v);
	Vec3 operator/(const Vec3& v);
	Vec3 operator%(const Vec3& v);

	Vec3 operator+(float f);
	Vec3 operator-(float f);
	Vec3 operator*(float f);
	Vec3 operator/(float f);
	Vec3 operator%(int i);
	
	//Assignment
	Vec3& operator+=(const Vec3& v);
	Vec3& operator-=(const Vec3& v);
	Vec3& operator*=(const Vec3& v);
	Vec3& operator/=(const Vec3& v);
	Vec3& operator%=(const Vec3& v);

	Vec3& operator+=(float f);
	Vec3& operator-=(float f);
	Vec3& operator*=(float f);
	Vec3& operator/=(float f);
	Vec3& operator%=(int i);

	Vec3& operator++(int i);
	Vec3& operator--(int i);

	//other
	bool operator==(const Vec3& v);
	bool operator!=(const Vec3& v);
	bool operator>=(const Vec3& v);
	bool operator<=(const Vec3& v);
	bool operator<(const Vec3& v);
	bool operator>(const Vec3& v);

	Vec3 operator-();
};

std::ostream& operator<<(std::ostream& os, const Vec3& v);