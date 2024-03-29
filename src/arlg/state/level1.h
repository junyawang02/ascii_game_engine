#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
#include "../entity/enemy.h"
#include <memory>

using std::unique_ptr;

class Player;

class Level1 : public Level {
    int doGetNumber() override;
    unique_ptr<Enemy> doGetEnemy(int x, int y, Player *p) override;
};

#endif
