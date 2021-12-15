#include "playerCollider.h"
#include "../entity/player.h"
#include "../entity/bullet.h"
#include "../entity/exit.h"
#include "../entity/enemy.h"
#include "../entity/health.h"
#include "../entity/boss.h"

PlayerCollider::PlayerCollider(Player *p): Collider{p}, player{p} {}

void PlayerCollider::doVisit(Player *e) {
    getImpl()->bounce(e);
}

void PlayerCollider::doVisit(Enemy *e) {
    getImpl()->bounce(e);
    player->addHealth(-1);
    Boss *b = dynamic_cast<Boss*>(e);
    if (b)
        b->changeDirection();
}

void PlayerCollider::doVisit(Bullet *e) {
    if (!e->invincible()) {
        player->addHealth(-1);
        getImpl()->destroyOther(e);
    }
}


void PlayerCollider::doVisit(Exit *e) {
    e->finish();
}

void PlayerCollider::doVisit(Health *e) {
    player->addHealth(1);
    getImpl()->destroyOther(e);
}
