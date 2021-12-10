#include "collider1.h"
#include"../engine/entity/entity.h"
#include "../engine/util/posn.h"

Collider::Collider(Entity *s): self{s} {};

void Collider::bounce(Entity &s) {
    Posn vel = s.moveVelocity();
    self->setVelocity(vel);
    s.setVelocity(vel * -1);
}
