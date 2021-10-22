#pragma once

struct Dim
{
	float w, h;
	Dim(float w = 0, float h = 0);
	float getRatioWH();
	float getRatioHW();
	Dim operator=(const Dim& newVector);
};