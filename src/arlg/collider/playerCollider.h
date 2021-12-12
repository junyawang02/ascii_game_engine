#ifndef PLAYER_COLLIDER
#define PLAYER_COLLIDER

#include "../../config/colDecider.h"

class PlayerCollider: public Collider {
    Player *player;
    void doVisit(Player &e) override;
    void doVisit(Enemy &e) override;
    void doVisit(Bullet &e) override;
    void doVisit(Exit &e) override;
public:
    PlayerCollider(Player *p);
};

#endif
