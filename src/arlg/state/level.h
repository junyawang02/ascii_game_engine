#ifndef LEVEL_H
#define LEVEL_H

#include "../../engine/state/state.h"
#include "../entity/enemy.h"
#include <memory>

using std::unique_ptr;

class Game;
class Player;

class Level : public State {
    void doCreate(Game &g) override;
    void doOnTick(Game &g) override;
    virtual int doGetNumber() = 0;
    virtual unique_ptr<Enemy> doGetEnemy(int x, int y, Player *p) = 0;

public:
    Level();
    int getNumber();
    unique_ptr<Enemy> getEnemy(int x, int y, Player *p);
};

#endif
