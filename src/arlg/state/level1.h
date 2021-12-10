#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
#include <memory>

using std::unique_ptr;

class Damageable;

class Level1 : public Level {
    unique_ptr<Damageable> doGetEnemy(int x, int y) override;
};

#endif
