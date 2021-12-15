#ifndef BOSSROOM_H
#define BOSSROOM_H

#include "../../engine/state/state.h"
#include "../entity/enemy.h"
#include <memory>

using std::unique_ptr;

class Game;

class BossRoom : public State {
    void doCreate(Game &g) override;

public:
    BossRoom();
};

#endif