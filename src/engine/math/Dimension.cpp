#include "Dimension.h"

Dimension::Dimension(float w, float h) : w(w), h(h) {}

Dimension Dimension::operator=(const Dimension& newVector)
{
	w = newVector.w;
	h = newVector.h;
	return *this;
}
