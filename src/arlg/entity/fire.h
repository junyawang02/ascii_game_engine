#ifndef FIRE_H
#define FIRE_H

#include "../../config/collider.h"
#include "../../engine/util/acceptor.h"
#include "arlgEntity.h"

class Fire : public Acceptor<ARLGEntity, Fire, Collider> {
    void doOnTick() override;

public:
    Fire(int x, int y);
};

#endif
