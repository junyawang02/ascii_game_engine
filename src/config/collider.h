#ifndef COLLIDER_H
#define COLLIDER_H

#include "../engine/util/visitor.h"
#include "colliderBase.h"
#include <memory>

class Entity;
class Player;
class Bullet;
class Enemy;
class Exit;
class Health;
class Message;
class Fire;
class Head;

class Collider : public Visitor<ColliderBase, Player, Bullet, Enemy, Exit, Health, Fire, Message, Head> {
public:
    Collider(Entity *s);
};

#endif
