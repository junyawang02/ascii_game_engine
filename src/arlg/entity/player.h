#ifndef PLAYER_H
#define PLAYER_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/colDecider.h"
#include "damageable.h"

using std::pair;

class Player: public Acceptor<Damageable, Player, Collider> {
    bool iframe;
    size_t control;
    void doOnTick() override;
    pair<Line, string> doUpdateStatus() override;
    pair<bool, bool> doEndState() override;
public:
    Player(int x, int y, size_t c);
    bool invincible();
};

#endif
