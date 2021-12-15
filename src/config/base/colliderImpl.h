#ifndef COLLIDERIMPL_H
#define COLLIDERIMPL_H

class Entity;

class ColliderImpl {
private:
    Entity *self;

public:
    ColliderImpl(Entity *s);
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
