#ifndef STALKER_H
#define STALKER_H

#include "../../config/colDecider.h"
#include "../../engine/entity/entity.h"
#include "enemy.h"

class Player;

class Stalker : public Enemy {
public:
    Stalker(int x, int y, Player *p);
};

#endif
