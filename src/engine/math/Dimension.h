#pragma once

struct Dimension
{
	float w, h;
	Dimension(float w = 0, float h = 0);
	Dimension operator=(const Dimension& newVector);
};