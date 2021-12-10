#ifndef PLAYER_H
#define PLAYER_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/colDecider.h"
#include "damageable.h"

class Player: public Acceptor<Damageable, Player, Collider> {
    size_t control;
    void doCreate() override;
    void doOnTick() override;
public:
    Player(int x, int y, size_t c);
};

#endif
