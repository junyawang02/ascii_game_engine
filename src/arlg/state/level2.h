#ifndef LEVEL2_H
#define LEVEL2_H

#include "../entity/enemy.h"
#include "level.h"
#include <memory>

using std::unique_ptr;

class Player;

class Level2 : public Level {
    int doGetNumber() override;
    unique_ptr<Enemy> doGetEnemy(int x, int y, Player *p) override;
};

#endif
