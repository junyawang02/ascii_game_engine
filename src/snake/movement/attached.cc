#include "attached.h"
#include "../../engine/entity/entity.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/util/posn.h"

Attached::Attached(Entity *ent) : MovementComponent{}, leader{ent}, lastVel{ent->getPastVelocity()} {}

Posn Attached::velocity(const Entity &e) {
    Posn temp = lastVel;
    lastVel = leader->getPastVelocity();
    return temp;
}
