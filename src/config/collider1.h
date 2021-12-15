#ifndef COLLIDER1_H
#define COLLIDER1_H

#include "../engine/util/visitor.h"

class Entity;
class Player;
class Bullet;
class Enemy;
class Exit;
class Health;
class Message;
class Fire;

class Collider : public Visitor<Player, Bullet, Enemy, Exit, Health, Fire, Message> {
protected:
    Entity *self;
public:
    Collider(Entity *s);
    void bounceSelf(Entity *s);
    void bounceOther(Entity *s);
    void bounce(Entity *s);
    void destroySelf();
    void destroyOther(Entity *s);
    void stopSelf();
    void stopOther(Entity *s);
    void stop(Entity *s);
};

#endif
