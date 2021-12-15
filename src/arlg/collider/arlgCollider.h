#ifndef ARLGCOLLIDER_H
#define ARLGCOLLIDER_H

#include "../../engine/util/visitor.h"
#include "../../config/collider.h"
#include <memory>

class Entity;
class Player;
class Bullet;
class Enemy;
class Exit;
class Health;
class Message;
class Fire;

class ARLGCollider : public Visitor<Collider, Player, Bullet, Enemy, Exit, Health, Fire, Message> {
public:
    ARLGCollider(Entity *s): Visitor{s} {}
};

#endif
