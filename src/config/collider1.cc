#include "collider1.h"
#include"../engine/entity/entity.h"
#include "../engine/util/posn.h"

Collider::Collider(Entity *s): self{s} {};

void Collider::bounceSelf(Entity &s) {
    Posn vel = s.getVelocity();
    self->setPos(self->getPos() + vel * 2);
}

void Collider::bounceOther(Entity &s) {
    Posn vel = s.getVelocity();
    s.setPos(s.getPos() - vel * 2);
}

void Collider::bounce(Entity &s) {
    bounceSelf(s);
    bounceOther(s);
}

void Collider::destroySelf() {
    self->flagDestroy();
}

void Collider::destroyOther(Entity &s) {
    s.flagDestroy();
}

