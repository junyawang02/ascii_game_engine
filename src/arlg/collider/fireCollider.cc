#include "fireCollider.h"
#include "../entity/enemy.h"
#include "../entity/player.h"
#include "../entity/fire.h"
#include "../entity/bullet.h"

FireCollider::FireCollider(Fire *f) : Collider{f} {}

void FireCollider::doVisit(Player *e) {
    e->addHealth(-0.5);
}

void FireCollider::doVisit(Enemy *e) {
    e->addHealth(-0.5);
}

void FireCollider::doVisit(Bullet *e) {
    getImpl()->stop(e);
    getImpl()->destroySelf();
    getImpl()->destroyOther(e);
}
