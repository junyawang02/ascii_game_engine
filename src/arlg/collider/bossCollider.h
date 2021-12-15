#ifndef BOSS_COLLIDER
#define BOSS_COLLIDER

#include "arlgCollider.h"

class Boss;

class BossCollider: public ARLGCollider {
    Boss *boss;
    void doVisit(Player *e) override;
    void doVisit(Bullet *e) override;
public:
    BossCollider(Boss *b);
};

#endif
