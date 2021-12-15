#include <enschin/Vec2i.h>


//Arithmetic 
Vec2i Vec2i::operator+(const Vec2i& v) {
    return {x + v.x, y + v.y};
}

Vec2i Vec2i::operator-(const Vec2i& v) {
    return {x - v.x, y - v.y};
}

Vec2i Vec2i::operator*(const Vec2i& v) {
    return {x * v.x, y * v.y};
}

Vec2i Vec2i::operator/(const Vec2i& v) {
    return {x / v.x, y / v.y};
}


//Assignment
Vec2i& Vec2i::operator+=(const Vec2i& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vec2i& Vec2i::operator-=(const Vec2i& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2i& Vec2i::operator*=(const Vec2i& v) {
    x *= v.x;
    y *= v.y;
    return *this;
}

Vec2i& Vec2i::operator/=(const Vec2i& v) {
    x /= v.x;
    y /= v.y;
    return *this;
}


//Relational
bool Vec2i::operator==(const Vec2i& v) {
    return x == v.x && y == v.y;
}

bool Vec2i::operator!=(const Vec2i& v) {
    return !(x == v.x && y == v.y);
}

//Other
Vec2i Vec2i::operator-() {
    return {-x, -y};
}

std::ostream& operator<<(std::ostream& os, const Vec2i& v) {
    os << "{" << v.x << ", " << v.y << "}";
    return os;
}
