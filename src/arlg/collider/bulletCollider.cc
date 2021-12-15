#include "bulletCollider.h"
#include "../entity/bullet.h"
#include "../entity/enemy.h"
#include "../entity/fire.h"
#include "../entity/player.h"

BulletCollider::BulletCollider(Bullet *b) : Collider{b}, bullet{b} {}

void BulletCollider::doVisit(Player &e) {
    if (!bullet->invincible()) {
        destroySelf();
        e.addHealth(-1);
    }
}

void BulletCollider::doVisit(Enemy &e) {
    destroySelf();
    if (!bullet->isFromEnemy())
        e.addHealth(-1);
}

void BulletCollider::doVisit(Bullet &e) {
    destroySelf();
    destroyOther(e);
}

void BulletCollider::doVisit(Fire &e) {
    stop(e);
    destroySelf();
    destroyOther(e);
}
