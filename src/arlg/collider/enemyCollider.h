#ifndef ENEMY_COLLIDER
#define ENEMY_COLLIDER

#include "../../config/colDecider.h"

class Enemy;

class EnemyCollider: public Collider {
    Enemy *enemy;
    void doVisit(Player &e) override;
    void doVisit(Enemy &e) override;
    void doVisit(Bullet &e) override;
public:
    EnemyCollider(Enemy *p);
};

#endif
