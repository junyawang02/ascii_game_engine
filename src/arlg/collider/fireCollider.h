#ifndef FIRE_COLLIDER
#define FIRE_COLLIDER

#include "../../config/collider.h"

class FireCollider : public Collider {
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;

public:
    FireCollider(Fire *f);
};

#endif
