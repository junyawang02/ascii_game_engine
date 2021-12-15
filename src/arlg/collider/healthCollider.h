#ifndef HEALTH_COLLIDER
#define HEALTH_COLLIDER

#include "../../config/collider.h"

class HealthCollider: public Collider {
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
public:
    HealthCollider(Health *h);
};

#endif
