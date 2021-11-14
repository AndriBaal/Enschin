#include "dim2.h"

Dim2::Dim2(float w, float h) : w(w), h(h) {}

bool Dim2::operator==(const Dim2& v) {
    return w == v.w && h == v.h;
}


