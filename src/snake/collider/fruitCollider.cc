#include "../entity/fruit.h"
#include "fruitCollider.h"
#include "../entity/head.h"

FruitCollider::FruitCollider(Fruit *f): Collider{f}, fruit{f} {}

void FruitCollider::doVisit(Head *e) {
    e->setGrow(true);
    destroySelf();
}
