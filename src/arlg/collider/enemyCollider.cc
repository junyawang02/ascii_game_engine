#include "enemyCollider.h"
#include "../entity/boss.h"
#include "../entity/bullet.h"
#include "../entity/enemy.h"
#include "../entity/health.h"
#include "../entity/player.h"

EnemyCollider::EnemyCollider(Enemy *p) : Collider{p}, enemy{p} {}

void EnemyCollider::doVisit(Player *e) {
    getImpl()->bounce(e);
    e->addHealth(-1);
}

void EnemyCollider::doVisit(Enemy *e) {
    Boss *boss = dynamic_cast<Boss *>(e);
    if (boss)
        return;
    getImpl()->bounce(e);
}

void EnemyCollider::doVisit(Bullet *e) {
    if (!e->isFromEnemy())
        enemy->addHealth(-1);
    getImpl()->destroyOther(e);
}

void EnemyCollider::doVisit(Health *e) {
    enemy->addHealth(1);
    getImpl()->destroyOther(e);
}
