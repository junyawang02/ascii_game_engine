#include "posn.h"

Posn::Posn(): x{0}, y{0} {}

Posn::Posn(int x, int y) : x{x}, y{y} {}

Posn::Posn(const Posn &other) : x{other.x}, y{other.y} {}

Posn &Posn::operator+=(const Posn &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Posn &Posn::operator-=(const Posn &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Posn &Posn::operator*=(int n) {
    x *= n;
    y *= n;
    return *this;
}

Posn operator+(const Posn &p1, const Posn &p2) {
    return Posn{p1.x + p2.x, p1.y + p2.y};
}

Posn operator-(const Posn &p1, const Posn &p2) {
    return Posn{p1.x - p2.x, p1.y - p2.y};
}

Posn operator*(const Posn &p, int n) {
    return Posn{p.x * n, p.y * n};
}
