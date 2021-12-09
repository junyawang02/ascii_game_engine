#ifndef ENTITY_H
#define ENTITY_H

#include "../movement/movement.h"
#include "../sprite/bitmap.h"
#include "../sprite/sprite.h"
#include "../util/posn.h"
#include "../util/action.h"
#include "../util/border.h"
#include "../client/collider.h"
#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

class Entity {
    int countdown;
    bool destroy;
    Posn pos;
    Posn vel;
    unique_ptr<Sprite> spr;
    unique_ptr<Movement> mvt;
    unique_ptr<Collider> col;
    vector<Action> acts = vector<Action>{Action::INVALID};

    virtual void doCreate() = 0;
    virtual void doOnTick() = 0;
    virtual void doAccept(Collider &v) = 0;
    virtual void doBorderCollide(Border b);

public:
    Entity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Movement> m, unique_ptr<Collider> c);
    virtual ~Entity() = default;

    void decrementCount();
    void resetCount();
    void flagDestroy();
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

    void setMovement(unique_ptr<Movement> m);
    Posn &moveVelocity();
    void setVelocity(Posn v);

    void create();
    void onTick();
};

#endif