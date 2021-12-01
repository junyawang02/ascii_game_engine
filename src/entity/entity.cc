#include "entity.h"

#include "../sprite/bitmap.h"
#include "../sprite/sprite.h"
#include "../util/posn.h"
#include <memory>

using std::unique_ptr;

Entity::Entity(int x, int y, unique_ptr<Sprite> s) : pos{Posn{x,y}}, theSprite{std::move(s)} {}

const Bitmap &Entity::spriteFrame() const {
    return theSprite->getFrame();
}

const Bitmap &Entity::nextForm() const {
    return theSprite->nextFrame();
}

void Entity::setSprite(unique_ptr<Sprite> spr) {
    theSprite = std::move(spr);
}

void Entity::create() { doCreate(); }

void Entity::onTick() { doOnTick(); }

Posn &Entity::getPos() { return pos; }

void Entity::setPos(int x, int y) { 
    pos.x = x;
    pos.y = y;
}