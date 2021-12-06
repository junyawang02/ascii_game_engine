#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../util/posn.h"

class Entity;

class Movement {
    virtual Posn velocity(const Entity &e) = 0;
public:
    virtual ~Movement() = default;
    Posn getVelocity(const Entity &e);
};

#endif
