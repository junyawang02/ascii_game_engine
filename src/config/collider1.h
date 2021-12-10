#ifndef COLLIDER1_H
#define COLLIDER1_H

#include "../engine/util/visitor.h"

class Entity;
class Player;
class Walker;

class Collider : public Visitor<Player, Walker>{
protected:
    Entity *self;
public:
    Collider(Entity *s);
    void bounce(Entity &s);
};

#endif
