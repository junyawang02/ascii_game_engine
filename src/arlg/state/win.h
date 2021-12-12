#ifndef WIN_H
#define WIN_H

#include "../../engine/state/state.h"

class Game;

class Win : public State {
    void doCreate(Game &g) override;

public:
    Win();
};

#endif
