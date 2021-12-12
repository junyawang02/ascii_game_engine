#ifndef LOSS_H
#define LOSS_H

#include "../../engine/state/state.h"

class Game;

class Loss : public State {
    void doCreate(Game &g) override;

public:
    Loss();
};

#endif
