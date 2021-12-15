#include "popupCollider.h"
#include "../entity/enemy.h"
#include "../entity/player.h"
#include "../entity/bullet.h"
#include "../entity/health.h"
#include "../entity/popup.h"

PopupCollider::PopupCollider(Popup *p) : Collider{p}, popup{p} {}

void PopupCollider::doVisit(Player &e) {
    bounce(e);
    e.addHealth(-1);
}

void PopupCollider::doVisit(Enemy &e) {
    bounce(e);
}

void PopupCollider::doVisit(Bullet &e) {
    if (!popup->invincible() && !e.isFromEnemy())
        popup->addHealth(-1);
    destroyOther(e);
}

void PopupCollider::doVisit(Health &e) {
    popup->addHealth(1);
    destroyOther(e);
}
