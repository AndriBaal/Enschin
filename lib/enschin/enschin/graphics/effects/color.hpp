#pragma once

/**
 * @brief Color datastructure with red, green, blue and alpha.
 * All values are between 0.0f and 1.0f.
 */
struct Color {
public:
	/**
	 * @brief Construct a new Color object. All Values are between 0.0f and 1.0f 
	 * (1.0f = 255 / 0.0f = 0)
	 * 
	 * @param r Red amount
	 * @param g Green amount
	 * @param b Blue amount
	 * @param a Alpha amount
	 */
	explicit Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f)
		: r(r), g(g), b(b), a(a) {}
	float r;
	float g;
	float b;
	float a;
};