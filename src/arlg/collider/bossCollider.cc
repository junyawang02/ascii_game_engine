#include "bossCollider.h"
#include "../entity/player.h"
#include "../entity/bullet.h"
#include "../entity/boss.h"

BossCollider::BossCollider(Boss *b) : Collider{b}, boss{b} {}

void BossCollider::doVisit(Player *e) {
    bounce(e);
    boss->changeDirection();
    e->addHealth(-1);
}

void BossCollider::doVisit(Bullet *e) {
    if (!e->isFromEnemy())
        boss->addHealth(-1);
    destroyOther(e);
}
