#ifndef GRAVITATE_H
#define GRAVITATE_H

#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

using std::unique_ptr;

enum Side { UP, RIGHT, DOWN, LEFT };

class Entity;

class Gravitate : public MovementDecorator {
    Side side;
    int speed;
    Posn velocity(const Entity &e) override;

public:
    Gravitate(Side s, int sp, unique_ptr<Movement> c);
};

#endif
