#ifndef FIRE_H
#define FIRE_H

#include "arlgEntity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/collider.h"

class Fire: public Acceptor<ARLGEntity, Fire, Collider> {
    void doOnTick() override;
public:
    Fire(int x, int y);
};

#endif
