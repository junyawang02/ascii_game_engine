#ifndef FOLLOW_H
#define FOLLOW_H

#include "../util/posn.h"
#include "movementComponent.h"

class Entity;

class Follow : public MovementComponent {
    Entity *leader;
    int speed;
    Posn velocity(const Entity &e) override;

public:
    Follow(Entity *ent, int s);
};

#endif
