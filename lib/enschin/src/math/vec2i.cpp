#include <enschin/vec2i.h>


//Arithmetic 
Vec2i Vec2i::operator+(const Vec2i& v) const {
    return {x + v.x, y + v.y};
}

Vec2i Vec2i::operator-(const Vec2i& v) const {
    return {x - v.x, y - v.y};
}

Vec2i Vec2i::operator*(const Vec2i& v) const {
    return {x * v.x, y * v.y};
}

Vec2i Vec2i::operator/(const Vec2i& v) const {
    return {x / v.x, y / v.y};
}

Vec2i Vec2i::operator*(int i) const {
    return {x * i, y * i};
}

Vec2i Vec2i::operator/(int i) const {
    return {x / i, y / i};
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

Vec2i& Vec2i::operator*=(int i) {
    x *= i;
    y *= i;
    return *this;
}

Vec2i& Vec2i::operator/=(int i) {
    x /= i;
    y /= i;
    return *this;
}


//Relational
bool Vec2i::operator==(const Vec2i& v) const {
    return x == v.x && y == v.y;
}

bool Vec2i::operator!=(const Vec2i& v) const {
    return !(x == v.x && y == v.y);
}

//Other
Vec2i Vec2i::operator-() const {
    return {-x, -y};
}

std::ostream& operator<<(std::ostream& os, const Vec2i& v) {
    os << "{" << v.x << ", " << v.y << "}";
    return os;
}
