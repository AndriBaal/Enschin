#include "Physics.h"


/**
 * @brief Check if 2 rays(lines) are intersecting
 * 
 * @param a Ray a
 * @param b Ray b
 * @return true Lines are intersecting
 * @return false Lines aren't intersecting
 */
bool Physics::isLineIntersecting(Ray2 a, Ray2 b) {
    float denominator = ((a.v2.x - a.v1.x) * (b.v2.y - b.v1.y)) - ((a.v2.y - a.v1.y) * (b.v2.x - b.v1.x));
    float numerator1 = ((a.v1.y - b.v1.y) * (b.v2.x - b.v1.x)) - ((a.v1.x - b.v1.x) * (b.v2.y - b.v1.y));
    float numerator2 = ((a.v1.y - b.v1.y) * (a.v2.x - a.v1.x)) - ((a.v1.x - b.v1.x) * (a.v2.y - a.v1.y));

    // Detect coincident lines (has a problem, read below)
    if (denominator == 0) return numerator1 == 0 && numerator2 == 0;
    
    float r = numerator1 / denominator;
    float s = numerator2 / denominator;

    return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);
}
