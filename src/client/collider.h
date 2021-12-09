#ifndef COLLIDER_H
#define COLLIDER_H

#include "../util/visitor.h"

class ClientEntity;
class Entity;

class Collider : public Visitor<ClientEntity>{
protected:
    Entity *self;
public:
    Collider(Entity *s);
};

#endif
