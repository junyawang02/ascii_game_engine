#ifndef COLLIDER_H
#define COLLIDER_H

#include "base/colliderBase.h"
#include <memory>

using std::unique_ptr;

class Entity;
class Head;

class Collider : public ColliderBase<Head> {
public:
    Collider(Entity *s): ColliderBase{s} {}
};

#endif
