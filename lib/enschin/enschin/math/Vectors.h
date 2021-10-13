#pragma once

class Vector3
{
public:
	float x, y, z;
	Vector3(float x = 0, float y = 0, float z = 0);
	void set(float x, float y, float z);
	Vector3 operator=(Vector3& newVector);
};

class Vector2
{
public:
	float x, y;
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