#ifndef ENEMY_COLLIDER
#define ENEMY_COLLIDER

#include "../../config/collider.h"

class Enemy;

class EnemyCollider : public Collider {
    Enemy *enemy;
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;
    void doVisit(Health *e) override;

public:
    EnemyCollider(Enemy *p);
};

#endif
