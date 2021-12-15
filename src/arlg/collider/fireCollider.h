#ifndef FIRE_COLLIDER
#define FIRE_COLLIDER

#include "arlgCollider.h"

class FireCollider: public ARLGCollider {
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;
public:
    FireCollider(Fire *f);
};

#endif
