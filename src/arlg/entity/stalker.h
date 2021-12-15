#ifndef STALKER_H
#define STALKER_H

#include "../../config/collider.h"
#include "../../engine/entity/entity.h"
#include "enemy.h"

class Player;

class Stalker : public Enemy {
    void doOnTick() override;
public:
    Stalker(int x, int y, Player *p);
};

#endif
