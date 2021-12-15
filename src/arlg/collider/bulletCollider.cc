#include "bulletCollider.h"
#include "../entity/enemy.h"
#include "../entity/player.h"
#include "../entity/bullet.h"
#include "../entity/fire.h"

BulletCollider::BulletCollider(Bullet *b) : Collider{b} {}

void BulletCollider::doVisit(Player &e) {
    if (!e.invincible()) {
        destroySelf();
        e.addHealth(-1);
    }
}

void BulletCollider::doVisit(Enemy &e) {
    destroySelf();
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
