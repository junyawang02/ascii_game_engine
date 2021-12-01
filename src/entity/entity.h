#ifndef ENTITY_H
#define ENTITY_H

#include "../sprite/bitmap.h"
#include "../sprite/sprite.h"
#include "../util/posn.h"
#include <memory>

using std::unique_ptr;

class Entity {
    Posn pos;
    unique_ptr<Sprite> theSprite;
    virtual void doCreate() = 0;
    virtual void doOnTick() = 0;

public:
    Entity(int x, int y, unique_ptr<Sprite> s);
    virtual ~Entity() = default;
    const Bitmap &spriteFrame() const;
    const Bitmap &nextForm() const;
    void setSprite(unique_ptr<Sprite> spr);
    void create();
    void onTick();
    Posn &getPos();
    void setPos(int x, int y);
};

#endif