#ifndef FRUIT_COLLIDER
#define FRUIT_COLLIDER

#include "../../config/collider.h"

class Fruit;

class FruitCollider: public Collider {
    Fruit *fruit;
    void doVisit(Head *e) override;
public:
    FruitCollider(Fruit *f);
};

#endif