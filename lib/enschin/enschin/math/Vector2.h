#pragma once

struct Vector2
{
	float x;
	float y;
	void set(float x, float y);
	void set(Vector2 v);
	float getRatioXY();
	float getRatioYX();
	Vector2(float x = 0, float y = 0);
	Vector2 operator=(const Vector2& newVector);
	Vector2 operator+(const Vector2& otherVector);
	Vector2 operator-(const Vector2& otherVector);
	Vector2 operator-();
};