#include "healthCollider.h"
#include "../entity/enemy.h"
#include "../entity/health.h"
#include "../entity/player.h"

HealthCollider::HealthCollider(Health *h) : Collider{h} {}

void HealthCollider::doVisit(Player *e) {
    e->addHealth(1);
    destroySelf();
}

void HealthCollider::doVisit(Enemy *e) {
    e->addHealth(1);
    destroySelf();
}
