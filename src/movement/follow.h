#ifndef FOLLOW_H
#define FOLLOW_H

#include "../util/posn.h"
#include "../entity/entity.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

using std::unique_ptr;

class Follow : public MovementDecorator {
    Entity *leader;
    int speed;
    Posn velocity(const Posn &pos) override;

public:
    Follow(Entity *ent, int s, unique_ptr<Movement> c);
};

#endif
