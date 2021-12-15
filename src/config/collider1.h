#ifndef COLLIDER_H
#define COLLIDER_H

#include "base/colliderBase.h"
#include <memory>

class Entity;
class Player;
class Bullet;
class Enemy;
class Exit;
class Health;
class Message;
class Fire;

class Collider : public ColliderBase<Player, Bullet, Enemy, Exit, Health, Fire, Message> {
public:
    Collider(Entity *s): ColliderBase{s} {}
};

#endif
