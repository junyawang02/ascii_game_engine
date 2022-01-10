#ifndef BOSS_COLLIDER
#define BOSS_COLLIDER

#include "../../config/collider.h"

class Boss;

class BossCollider : public Collider {
    Boss *boss;
    void doVisit(Player *e) override;
    void doVisit(Bullet *e) override;

public:
    BossCollider(Boss *b);
};

#endif
