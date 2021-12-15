#ifndef ARLG_H
#define ARLG_H

#include "../../engine/model/game.h"

class ARLG : public Game {
    void doEndState(bool win) override;
public:
    ARLG();
};

#endif
