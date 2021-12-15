#ifndef BLACKOUT_H
#define BLACKOUT_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/collider.h"

class Blackout : public Acceptor<Entity, Blackout, Collider> {
    int time;
    void doOnTick() override;
public:
    Blackout();
};

#endif
