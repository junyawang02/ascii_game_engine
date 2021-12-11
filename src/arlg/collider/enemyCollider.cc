#include "enemyCollider.h"
#include "../entity/damageable.h"
#include "../entity/walker.h"
#include "../entity/player.h"
#include "../entity/bullet.h"

EnemyCollider::EnemyCollider(Damageable *p) : Collider{p}, enemy{p} {}

void EnemyCollider::doVisit(Player &e) {
    bounce(e);
    e.addHealth(-1);
}

void EnemyCollider::doVisit(Walker &e) {
    bounce(e);
}

void EnemyCollider::doVisit(Bullet &e) {
    enemy->addHealth(-1);
    destroyOther(e);
}
