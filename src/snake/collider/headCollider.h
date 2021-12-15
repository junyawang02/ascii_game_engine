#ifndef HEAD_COLLIDER
#define HEAD_COLLIDER

#include "../../config/collider.h"

class Head;

class HeadCollider: public Collider {
    Head *head;
    void doVisit(Fruit *e) override;
    void doVisit(Tail *e) override;
public:
    HeadCollider(Head *h);
};

#endif