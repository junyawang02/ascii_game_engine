#ifndef HEALTH_COLLIDER
#define HEALTH_COLLIDER

#include "arlgCollider.h"

class HealthCollider: public ARLGCollider {
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
public:
    HealthCollider(Health *h);
};

#endif
