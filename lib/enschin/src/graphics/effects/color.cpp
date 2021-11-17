#include "color.h"

/**
 * @brief Construct a new Color object. All Values are between 0.0f and 1.0f
 * (1.0f = 255 / 0.0f = 0)
 *
 * @param r Red amount
 * @param g Green amount
 * @param b Blue amount
 * @param a Alpha amount
 */
Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

void Color::invert() {
    r = 1.0-r;
    g = 1.0-r;
    b = 1.0-r;
}
