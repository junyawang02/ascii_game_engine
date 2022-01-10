#ifndef BOSS_H
#define BOSS_H

#include "../../config/collider.h"
#include "../../engine/entity/entity.h"
#include "enemy.h"

using std::pair;

class Player;

class Boss : public Enemy {
    Player *player;
    bool angry;
    void doCreate() override;
    void doOnTick() override;
    void doBorderCollide(Border b) override;
    pair<Line, string> doUpdateStatus() override;
    pair<bool, bool> doEndState() override;

public:
    Boss(int x, int y, Player *p);
    void changeDirection();
};

#endif
