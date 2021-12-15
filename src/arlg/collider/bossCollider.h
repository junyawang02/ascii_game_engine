#ifndef BOSS_COLLIDER
#define BOSS_COLLIDER

#include "../../config/colDecider.h"

class Boss;

class BossCollider: public Collider {
    Boss *boss;
    void doVisit(Player *e) override;
    void doVisit(Bullet *e) override;
public:
    BossCollider(Boss *b);
};

#endif
