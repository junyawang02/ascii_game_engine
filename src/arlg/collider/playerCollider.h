#ifndef PLAYER_COLLIDER
#define PLAYER_COLLIDER

#include "arlgCollider.h"

class PlayerCollider: public ARLGCollider {
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
