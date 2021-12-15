#ifndef ATTACHED_H
#define ATTACHED_H

#include "../../engine/util/posn.h"
#include "../../engine/movement/movementComponent.h"

class Entity;

class Attached : public MovementComponent {
    Entity *leader;
    Posn lastVel;
    Posn velocity(const Entity &e) override;

public:
    Attached(Entity *ent);
};

#endif
