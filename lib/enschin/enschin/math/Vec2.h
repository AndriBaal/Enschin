#pragma once

struct Vec2 {
	float x;
	float y;
	void set(float x, float y);
	void set(Vec2 v);
	float getRatioXY();
	float getRatioYX();
	Vec2(float x = 0, float y = 0);
	Vec2 operator=(const Vec2& newVector);
	Vec2 operator+(const Vec2& otherVector);
	Vec2 operator-(const Vec2& otherVector);
	Vec2 operator-();
};