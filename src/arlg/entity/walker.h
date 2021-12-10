#ifndef WALKER_H
#define WALKER_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/colDecider.h"
#include "damageable.h"

class Walker: public Acceptor<Damageable, Walker, Collider> {
    int changeDir;
    int dir;
    void doCreate() override;
    void doOnTick() override;
public:
    Walker(int x, int y);
    void changeDirection();
};

#endif
