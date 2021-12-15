#ifndef TAIL_H
#define TAIL_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/collider.h"

class Entity;

class Tail : public Acceptor<Entity, Tail, Collider> {
public:
    Tail(int x, int y, Entity *lead);
};

#endif