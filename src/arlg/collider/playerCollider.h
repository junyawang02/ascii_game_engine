#ifndef PLAYER_COLLIDER
#define PLAYER_COLLIDER

#include "../../config/collider.h"

class PlayerCollider : public Collider {
    Player *player;
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;
    void doVisit(Exit *e) override;
    void doVisit(Health *e) override;

public:
    PlayerCollider(Player *p);
};

#endif
