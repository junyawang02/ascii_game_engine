#ifndef FRUIT_H
#define FRUIT_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/collider.h"

class Fruit : public Acceptor<Entity, Fruit, Collider> {
    void doCreate() override;
public:
    Fruit(int x, int y);
};

#endif