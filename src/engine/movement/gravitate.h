#ifndef GRAVITATE_H
#define GRAVITATE_H

#include "../util/border.h"
#include "../util/posn.h"
#include "movementComponent.h"

class Entity;

class Gravitate : public MovementComponent {
    Border side;
    int speed;
    Posn velocity(const Entity &e) override;

public:
    Gravitate(Border s, int sp);
};

#endif
