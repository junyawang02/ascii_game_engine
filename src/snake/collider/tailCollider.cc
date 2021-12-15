#include "tailCollider.h"
#include "../entity/head.h"
#include "../entity/tail.h"

TailCollider::TailCollider(Tail *t) : Collider{t}, tail{t} {}

void TailCollider::doVisit(Head *e) {
    e->startCount();
}
