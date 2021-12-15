#include "colliderImpl.h"
#include "../../engine/entity/entity.h"
#include "../../engine/util/posn.h"

ColliderImpl::ColliderImpl(Entity *s): self{s} {}

void ColliderImpl::bounceSelf(Entity *s) {
    Posn vel = s->getPastVelocity();
    self->setPos(self->getPos() + vel * 2);
}

void ColliderImpl::bounceOther(Entity *s) {
    Posn vel = s->getPastVelocity();
    s->setPos(s->getPos() - vel * 2);
}

void ColliderImpl::bounce(Entity *s) {
    bounceSelf(s);
    bounceOther(s);
}

void ColliderImpl::destroySelf() {
    self->flagDestroy();
}

void ColliderImpl::destroyOther(Entity *s) {
    s->flagDestroy();
}

void ColliderImpl::stopSelf() {
    self->setVelocity(Posn{0, 0});
}

void ColliderImpl::stopOther(Entity *s) {
    s->setVelocity(Posn{0, 0});
}

void ColliderImpl::stop(Entity *s) {
    stopSelf();
    stopOther(s);
}