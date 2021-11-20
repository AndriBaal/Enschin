#pragma once
#include <box2d/b2_math.h>
#include <ostream>

/**
 * @brief Data structure that holds 2 floats.
 */
struct Vec2 {
	float x, y;
	Vec2(float x = 0, float y = 0) : x(x), y(y){};

    const static Vec2 nullVec2;

    b2Vec2 toBox(){ return b2Vec2(x, y); }

	//Arithmetic 
	Vec2 operator+(const Vec2& v);
	Vec2 operator-(const Vec2& v);
	Vec2 operator*(const Vec2& v);
	Vec2 operator/(const Vec2& v);
	Vec2 operator%(const Vec2& v);

	Vec2 operator+(float f);
	Vec2 operator-(float f);
	Vec2 operator*(float f);
	Vec2 operator/(float f);
	Vec2 operator%(int i);
	
	//Assignment
	Vec2& operator+=(const Vec2& v);
	Vec2& operator-=(const Vec2& v);
	Vec2& operator*=(const Vec2& v);
	Vec2& operator/=(const Vec2& v);
	Vec2& operator%=(const Vec2& v);

	Vec2& operator+=(float f);
	Vec2& operator-=(float f);
	Vec2& operator*=(float f);
	Vec2& operator/=(float f);
	Vec2& operator%=(int i);

	Vec2& operator++(int i);
	Vec2& operator--(int i);

	//other
	bool operator==(const Vec2& v);
	bool operator!=(const Vec2& v);
	bool operator>=(const Vec2& v);
	bool operator<=(const Vec2& v);
	bool operator<(const Vec2& v);
	bool operator>(const Vec2& v);

	Vec2 operator-();
};

std::ostream& operator<<(std::ostream& os, const Vec2& v);
