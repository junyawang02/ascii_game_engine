#ifndef COLLIDER1_H
#define COLLIDER1_H

#include "../engine/util/visitor.h"

class Entity;
class Player;
class Bullet;
class Walker;
class Message;

class Collider : public Visitor<Player, Bullet, Walker, Message>{
protected:
    Entity *self;
public:
    Collider(Entity *s);
    void bounceSelf(Entity &s);
    void bounceOther(Entity &s);
    void bounce(Entity &s);
    void destroySelf();
    void destroyOther(Entity &s);
};

#endif
