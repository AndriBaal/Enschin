#pragma once

struct Vector3
{
	float x, y, z;
	Vector3(float x = 0, float y = 0, float z = 0);
	void set(float x, float y, float z);
	Vector3 operator=(Vector3& newVector);
};

struct Vector2
{
	float x, y;
	Vector2(float x = 0, float y = 0);
	Vector2 operator=(const Vector2& newVector);
	Vector2 operator+(const Vector2& otherVector);
};