#ifndef TAIL_COLLIDER
#define TAIL_COLLIDER

#include "../../config/collider.h"

class Tail;

class TailCollider: public Collider {
    Tail *tail;
    void doVisit(Head *e) override;
public:
    TailCollider(Tail *t);
};

#endif