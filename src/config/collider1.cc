#include "collider1.h"
#include"../engine/entity/entity.h"
#include "../engine/util/posn.h"

Collider::Collider(Entity *s): self{s} {};

void Collider::bounce(Entity &s) {
    Posn vel = s.getVelocity();
    self->setVelocity(Posn{0, 0});
    self->setPos(self->getPos() + vel * 2);
    s.setVelocity(Posn{0, 0});
    s.setPos(s.getPos() - vel * 2);
}
