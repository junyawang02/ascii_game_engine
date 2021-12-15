#include "bulletCollider.h"
#include "../entity/bullet.h"
#include "../entity/enemy.h"
#include "../entity/fire.h"
#include "../entity/player.h"
#include "../entity/popup.h"
#include "../entity/snake.h"

BulletCollider::BulletCollider(Bullet *b) : Collider{b}, bullet{b} {}

void BulletCollider::doVisit(Player *e) {
    if (!bullet->invincible()) {
        destroySelf();
        e->addHealth(-1);
    }
}

void BulletCollider::doVisit(Enemy *e) {
    destroySelf();
    if (!bullet->isFromEnemy()) {
        Popup *p = dynamic_cast<Popup *>(e);
        if (p) {
            if (!p->invincible())
                e->addHealth(-1);
        } else {
            Snake *s = dynamic_cast<Snake *>(e);
            if (s) {
                if (s->getPos() != bullet->getPos())
                    e->addHealth(-1);
            } else {
                e->addHealth(-1);
            }
        }
    }
}

void BulletCollider::doVisit(Bullet *e) {
    destroySelf();
    destroyOther(e);
}

void BulletCollider::doVisit(Fire *e) {
    stop(e);
    destroySelf();
    destroyOther(e);
}
