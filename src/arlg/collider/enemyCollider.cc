#include "enemyCollider.h"
#include "../entity/enemy.h"
#include "../entity/player.h"
#include "../entity/bullet.h"
#include "../entity/health.h"

EnemyCollider::EnemyCollider(Enemy *p) : Collider{p}, enemy{p} {}

void EnemyCollider::doVisit(Player *e) {
    bounce(e);
    e->addHealth(-1);
}

void EnemyCollider::doVisit(Enemy *e) {
    bounce(e);
}

void EnemyCollider::doVisit(Bullet *e) {
    if (!e->isFromEnemy())
        enemy->addHealth(-1);
    destroyOther(e);
}

void EnemyCollider::doVisit(Health *e) {
    enemy->addHealth(1);
    destroyOther(e);
}
