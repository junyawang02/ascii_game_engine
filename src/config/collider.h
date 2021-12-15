#ifndef COLLIDER_H
#define COLLIDER_H

class Entity;
class Player;
class Bullet;
class Enemy;
class Exit;
class Health;
class Message;
class Fire;

class Collider {
private:
    Entity *self;
    virtual void doVisit(Player *e) = 0;
    virtual void doVisit(Bullet *e) = 0;
    virtual void doVisit(Enemy *e) = 0;
    virtual void doVisit(Exit *e) = 0;
    virtual void doVisit(Health *e) = 0;
    virtual void doVisit(Message *e) = 0;
    virtual void doVisit(Fire *e) = 0;

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

    void visit(Player *e);
    void visit(Bullet *e);
    void visit(Enemy *e);
    void visit(Exit *e);
    void visit(Health *e);
    void visit(Message *e);
    void visit(Fire *e);
};

#endif

