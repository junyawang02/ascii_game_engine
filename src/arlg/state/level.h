#ifndef LEVEL_H
#define LEVEL_H

#include "../../engine/state/state.h"
#include <memory>

using std::unique_ptr;

class Damageable;

class Level : public State {
    void doCreate() override;
    void doOnTick() override;
    virtual unique_ptr<Damageable> doGetEnemy(int x, int y) = 0;
public:
    Level();
    unique_ptr<Damageable> getEnemy(int x, int y);
};

#endif