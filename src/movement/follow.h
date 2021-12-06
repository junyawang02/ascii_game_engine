#ifndef FOLLOW_H
#define FOLLOW_H

#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

using std::unique_ptr;

class Entity;

class Follow : public MovementDecorator {
    Entity *leader;
    int speed;
    Posn velocity(const Entity &e) override;

public:
    Follow(Entity *ent, int s, unique_ptr<Movement> c);
};

#endif
