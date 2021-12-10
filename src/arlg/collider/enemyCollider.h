#ifndef ENEMY_COLLIDER
#define ENEMY_COLLIDER

#include "../../config/colDecider.h"

class Damageable;

class EnemyCollider: public Collider {
    Damageable *enemy;
    void doVisit(Player &e) override;
    void doVisit(Walker &e) override;
public:
    EnemyCollider(Damageable *p);
};

#endif
