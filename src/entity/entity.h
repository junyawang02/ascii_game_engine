#ifndef ENTITY_H
#define ENTITY_H

#include "../movement/movement.h"
#include "../sprite/bitmap.h"
#include "../sprite/sprite.h"
#include "../util/posn.h"
#include <memory>

using std::unique_ptr;

class Entity {
    int countdown;
    bool destroy;
    Posn pos;
    unique_ptr<Sprite> spr;
    unique_ptr<Movement> mvt;

    virtual void doCreate() = 0;
    virtual void doOnTick() = 0;

public:
    Entity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Movement> m);
    virtual ~Entity() = default;

    void decrementCount();
    void resetCount();
    void flagDestroy();
    bool getDestroy();

    Posn &getPos();
    void setPos(int x, int y);

    void setSprite(unique_ptr<Sprite> s);
    const Bitmap &spriteFrame() const;
    const Bitmap &nextForm() const;

    void setMovement(unique_ptr<Movement> m);
    const Posn moveVelocity() const;

    void create();
    void onTick();
};

#endif