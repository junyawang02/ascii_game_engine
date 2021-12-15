#include "collider.h"
#include"../engine/entity/entity.h"
#include "../engine/util/posn.h"

Collider::Collider(Entity *s): self{s} {};

void Collider::bounceSelf(Entity *s) {
    Posn vel = s->getPastVelocity();
    self->setPos(self->getPos() + vel * 2);
}

void Collider::bounceOther(Entity *s) {
    Posn vel = s->getPastVelocity();
    s->setPos(s->getPos() - vel * 2);
}

void Collider::bounce(Entity *s) {
    bounceSelf(s);
    bounceOther(s);
}

void Collider::destroySelf() {
    self->flagDestroy();
}

void Collider::destroyOther(Entity *s) {
    s->flagDestroy();
}

void Collider::stopSelf() {
    self->setVelocity(Posn{0, 0});
}

void Collider::stopOther(Entity *s) {
    s->setVelocity(Posn{0, 0});
}

void Collider::stop(Entity *s) {
    stopSelf();
    stopOther(s);
}

void Collider::visit(Player *e) { doVisit(e); }

void Collider::visit(Bullet *e) { doVisit(e); }

void Collider::visit(Enemy *e) { doVisit(e); }

void Collider::visit(Exit *e) { doVisit(e); }

void Collider::visit(Health *e) { doVisit(e); }

void Collider::visit(Message *e) { doVisit(e); }

void Collider::visit(Fire *e) { doVisit(e); }
