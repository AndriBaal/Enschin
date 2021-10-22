#include "Dim.h"

Dim::Dim(float w, float h) : w(w), h(h) {}

Dim Dim::operator=(const Dim& newVector)
{
	w = newVector.w;
	h = newVector.h;
	return *this;
}

float Dim::getRatioWH()
{
	return w / h;
}

float Dim::getRatioHW()
{
	return h / w;
}