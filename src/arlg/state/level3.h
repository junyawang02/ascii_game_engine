#ifndef LEVEL3_H
#define LEVEL3_H

#include "../entity/enemy.h"
#include "level.h"
#include <memory>

using std::unique_ptr;

class Player;

class Level3 : public Level {
    int doGetNumber() override;
    unique_ptr<Enemy> doGetEnemy(int x, int y, Player *p) override;
};

#endif
