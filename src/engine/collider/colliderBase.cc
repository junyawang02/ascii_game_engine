#include "colliderBase.h"
#include "../entity/entity.h"
#include "../util/posn.h"

ColliderBase::ColliderBase(Entity *s) : self{s} {};

void ColliderBase::bounceSelf(Entity *s) {
    Posn vel = s->getPastVelocity();
    self->setPos(self->getPos() + vel * 2);
}

void ColliderBase::bounceOther(Entity *s) {
    Posn vel = s->getPastVelocity();
    s->setPos(s->getPos() - vel * 2);
}

void ColliderBase::bounce(Entity *s) {
    bounceSelf(s);
    bounceOther(s);
}

void ColliderBase::destroySelf() {
    self->flagDestroy();
}

void ColliderBase::destroyOther(Entity *s) {
    s->flagDestroy();
}

void ColliderBase::stopSelf() {
    self->setVelocity(Posn{0, 0});
}

void ColliderBase::stopOther(Entity *s) {
    s->setVelocity(Posn{0, 0});
}

void ColliderBase::stop(Entity *s) {
    stopSelf();
    stopOther(s);
}
