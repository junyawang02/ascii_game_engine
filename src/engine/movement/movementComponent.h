#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include "../util/posn.h"

class Entity;

class MovementComponent {
    virtual Posn velocity(const Entity &e) = 0;
public:
    virtual ~MovementComponent() = default;
    Posn getVelocity(const Entity &e);
};

#endif
