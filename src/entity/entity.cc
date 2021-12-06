#include "entity.h"
#include "../movement/movement.h"
#include "../sprite/bitmap.h"
#include "../sprite/sprite.h"
#include "../util/posn.h"
#include <memory>

using std::unique_ptr;

Entity::Entity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Movement> m) : countdown{5}, destroy{false}, pos{Posn{x, y}}, spr{std::move(s)}, mvt{std::move(m)} {}

void Entity::decrementCount() { 
    if (countdown == 0)
        flagDestroy();
    --countdown; 
}

void Entity::resetCount() { countdown = 5; }

void Entity::flagDestroy() { destroy = true; }

bool Entity::getDestroy() { return destroy; }

const Posn &Entity::getPos() const { return pos; }

void Entity::setPos(const Posn &p) {
    pos = p;
}

void Entity::setPos(int x, int y) {
    pos.x = x;
    pos.y = y;
}

void Entity::setSprite(unique_ptr<Sprite> s) { spr = std::move(s); }

const Bitmap &Entity::spriteFrame() const { return spr->getFrame(); }

const Bitmap &Entity::nextForm() const { return spr->nextFrame(); }

void Entity::setMovement(unique_ptr<Movement> m) { mvt = std::move(m); }

const Posn Entity::moveVelocity() const { return mvt->getVelocity(*this); }

void Entity::create() { doCreate(); }

void Entity::onTick() { doOnTick(); }
