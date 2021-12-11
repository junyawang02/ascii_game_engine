#ifndef BULLET_COLLIDER
#define BULLET_COLLIDER

#include "../../config/colDecider.h"

class BulletCollider: public Collider {
    void doVisit(Player &e) override;
    void doVisit(Walker &e) override;
    void doVisit(Bullet &e) override;
public:
    BulletCollider(Entity *e);
};

#endif
