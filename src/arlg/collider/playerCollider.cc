#include "playerCollider.h"
#include "../entity/player.h"
#include "../entity/walker.h"
#include "../entity/bullet.h"
#include "../entity/exit.h"
#include "../entity/damageable.h"

PlayerCollider::PlayerCollider(Player *p): Collider{p}, player{p} {}

void PlayerCollider::doVisit(Player &e) {
    bounce(e);
}

void PlayerCollider::doVisit(Enemy &e) {
    bounce(e);
    player->addHealth(-1);
}

void PlayerCollider::doVisit(Bullet &e) {
    player->addHealth(-1);
    destroyOther(e);
}

void PlayerCollider::doVisit(Exit &e) {
    e.finish();
}
