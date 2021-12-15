#ifndef BULLET_COLLIDER
#define BULLET_COLLIDER

#include "../../config/colDecider.h"

class BulletCollider: public Collider {
    Bullet *bullet;
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;
    void doVisit(Fire *e) override;
public:
    BulletCollider(Bullet *b);
};

#endif
