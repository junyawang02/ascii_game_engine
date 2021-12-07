#ifndef POSN_H
#define POSN_H

struct Posn {
    int x;
    int y;
    Posn();
    Posn(int x, int y);
    Posn(const Posn &other);
    Posn &operator+=(const Posn &other);
    Posn &operator-=(const Posn &other);
    Posn &operator*=(int n);
};

Posn operator+(const Posn &p1, const Posn &p2);
Posn operator-(const Posn &p1, const Posn &p2);
Posn operator*(const Posn &p, int n);

#endif
