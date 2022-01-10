#ifndef ENTITY_H
#define ENTITY_H

#include "../../config/collider.h"
#include "../movement/movement.h"
#include "../movement/movementComponent.h"
#include "../sprite/bitmap.h"
#include "../sprite/sprite.h"
#include "../util/action.h"
#include "../util/border.h"
#include "../util/line.h"
#include "../util/posn.h"
#include <list>
#include <memory>
#include <string>
#include <vector>

using std::list;
using std::pair;
using std::string;
using std::unique_ptr;
using std::vector;

class Entity {
    int countdown;
    bool destroy;
    Posn pos;
    Posn vel;
    Posn pastVel;
    unique_ptr<Sprite> spr;
    unique_ptr<Movement> mvt;
    unique_ptr<Collider> col;
    list<unique_ptr<Entity>> spawns;
    vector<Action> acts;

    virtual void doCreate();
    virtual void doOnTick();
    virtual void doAccept(Collider &v) = 0;
    virtual void doBorderCollide(Border b);
    virtual pair<Line, string> doUpdateStatus();
    virtual pair<bool, bool> doEndState();

protected:
    void addSpawn(unique_ptr<Entity> e);

public:
    Entity(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m, unique_ptr<Collider> c);
    Entity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c);
    virtual ~Entity() = default;

    void decrementCount();
    void resetCount();
    void flagDestroy();
    void setDestroy(bool des);
    bool getDestroy();

    const Posn &getPos() const;
    void setPos(const Posn &p);
    void setPos(int x, int y);
    void addX(int n);
    void addY(int n);

    void setSprite(unique_ptr<Sprite> s);
    const Bitmap &spriteFrame() const;
    const Bitmap &nextForm() const;
    const vector<int> &dimensions() const;

    const vector<Action> &getActions() const;
    void setActions(const vector<Action> &inputs);

    Collider &getCollider();
    void accept(Collider &v);
    void borderCollide(Border b);

    void addMovement(string s, unique_ptr<MovementComponent> m);
    void removeMovement(string s);
    void clearMovement();
    Posn &moveVelocity();
    Posn getPastVelocity();
    void setVelocity(Posn v);

    list<unique_ptr<Entity>> &getSpawns();
    void clearSpawns();

    pair<Line, string> updateStatus();
    pair<bool, bool> endState();

    void create();
    void onTick();
};

#endif