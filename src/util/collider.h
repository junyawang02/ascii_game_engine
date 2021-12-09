#ifndef COLLIDER_H
#define COLLIDER_H

#include "../entity/entity.h"

class Collider {
public:
    virtual void collide(Entity &other) = 0;
};

#endif
