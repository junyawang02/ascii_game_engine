#include "healthCollider.h"
#include "../entity/player.h"
#include "../entity/enemy.h"
#include "../entity/health.h"

HealthCollider::HealthCollider(Health *h): ARLGCollider{h} {}

void HealthCollider::doVisit(Player *e) {
    e->addHealth(1);
    destroySelf();
}

void HealthCollider::doVisit(Enemy *e) {
    e->addHealth(1);
    destroySelf();
}
