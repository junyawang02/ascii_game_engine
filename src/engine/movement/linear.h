#ifndef LINEAR_H
#define LINEAR_H

#include "../util/posn.h"
#include "movementComponent.h"

class Entity;

class Linear : public MovementComponent {
    Posn vel;
    Posn velocity(const Entity &e) override;

public:
    Linear(int x, int y);
};

#endif
