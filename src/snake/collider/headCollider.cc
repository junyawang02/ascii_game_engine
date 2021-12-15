#include "headCollider.h"
#include "../entity/fruit.h"
#include "../entity/head.h"
#include "../entity/tail.h"

HeadCollider::HeadCollider(Head *h) : Collider{h}, head{h} {}

void HeadCollider::doVisit(Fruit *e) {
    head->setGrow(true);
    destroyOther(e);
}

void HeadCollider::doVisit(Tail *e) {
    head->startCount();
}
