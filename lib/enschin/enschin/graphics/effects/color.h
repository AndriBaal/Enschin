#pragma once

/**
 * @brief Color datastructure with red, green, blue and alpha.
 * All values are between 0.0f and 1.0f.
 */
struct Color {
public:
    Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f);
	float r;
	float g;
	float b;
	float a;

    void invert();
};