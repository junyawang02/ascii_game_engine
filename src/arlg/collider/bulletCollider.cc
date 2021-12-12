#include "bulletCollider.h"
#include "../entity/walker.h"
#include "../entity/player.h"
#include "../entity/bullet.h"

BulletCollider::BulletCollider(Entity *e) : Collider{e} {}

void BulletCollider::doVisit(Player &e) {
    destroySelf();
    e.addHealth(-1);
}

void BulletCollider::doVisit(Enemy &e) {
    destroySelf();
    e.addHealth(-1);
}

void BulletCollider::doVisit(Bullet &e) {
    destroySelf();
    destroyOther(e);
}
