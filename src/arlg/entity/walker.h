#ifndef WALKER_H
#define WALKER_H

#include "../../engine/entity/entity.h"
#include "../../config/colDecider.h"
#include "enemy.h"

class Walker: public Enemy {
    int changeDir;
    int dir;
    void doCreate() override;
    void doOnTick() override;
public:
    Walker(int x, int y);
    void changeDirection();
};

#endif
