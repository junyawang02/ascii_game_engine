#ifndef PLAYER_COLLIDER
#define PLAYER_COLLIDER

#include "../../config/colDecider.h"

class PlayerCollider: public Collider {
    Player *player;
    void doVisit(Player &e) override;
    void doVisit(Walker &e) override;
public:
    PlayerCollider(Player *p);
};

#endif
