#include "enemyCollider.h"
#include "../entity/enemy.h"
#include "../entity/walker.h"
#include "../entity/player.h"
#include "../entity/bullet.h"

EnemyCollider::EnemyCollider(Enemy *p) : Collider{p}, enemy{p} {}

void EnemyCollider::doVisit(Player &e) {
    bounce(e);
    e.addHealth(-1);
}

void EnemyCollider::doVisit(Enemy &e) {
    bounce(e);
}

void EnemyCollider::doVisit(Bullet &e) {
    enemy->addHealth(-1);
    destroyOther(e);
}
