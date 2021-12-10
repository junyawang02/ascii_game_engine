#ifndef GRAVITATE_H
#define GRAVITATE_H

#include "../util/posn.h"
#include "../util/border.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

using std::unique_ptr;

class Entity;

class Gravitate : public MovementDecorator {
    Border side;
    int speed;
    Posn velocity(const Entity &e) override;

public:
    Gravitate(Border s, int sp, unique_ptr<Movement> c);
};

#endif
