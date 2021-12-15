#ifndef COLLIDERBASE_H
#define COLLIDERBASE_H

class Entity;
class Player;
class Bullet;
class Enemy;
class Exit;
class Health;
class Message;
class Fire;

class ColliderBase {
private:
    Entity *self;

public:
    ColliderBase(Entity *s);
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

