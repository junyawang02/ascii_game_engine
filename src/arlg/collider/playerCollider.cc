#include "playerCollider.h"
#include "../entity/player.h"
#include "../entity/walker.h"
#include "../entity/damageable.h"

PlayerCollider::PlayerCollider(Player *p): Collider{p}, player{p} {}

void PlayerCollider::doVisit(Player &e) {
    bounce(e);
}

void PlayerCollider::doVisit(Walker &e) {
    bounce(e);
    player->addHealth(-1);
}
