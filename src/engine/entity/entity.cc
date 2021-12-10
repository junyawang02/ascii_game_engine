#include "entity.h"
#include "../movement/movement.h"
#include "../movement/movementComponent.h"
#include "../sprite/bitmap.h"
#include "../sprite/sprite.h"
#include "../util/action.h"
#include "../util/border.h"
#include "../util/posn.h"
#include <memory>
#include <string>
#include <vector>

using std::make_unique;
using std::string;
using std::unique_ptr;
using std::vector;

void Entity::doBorderCollide(Border b) {
    switch (b) {
    case Border::U:
        addY(1);
        break;
    case Border::D:
        addY(-1);
        break;
    case Border::R:
        addX(-1);
        break;
    case Border::L:
        addX(1);
        break;
    default:
        break;
    }
}

Entity::Entity(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m, unique_ptr<Collider> c) : countdown{5}, destroy{false}, pos{Posn{x, y}}, spr{std::move(s)}, mvt{make_unique<Movement>(std::move(m))}, col{std::move(c)} {}

Entity::Entity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c) : countdown{5}, destroy{false}, pos{Posn{x, y}}, spr{std::move(s)}, mvt{make_unique<Movement>()}, col{std::move(c)} {}

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

void Entity::addX(int n) { pos.x += n; }

void Entity::addY(int n) { pos.y += n; }

void Entity::setSprite(unique_ptr<Sprite> s) { spr = std::move(s); }

const Bitmap &Entity::spriteFrame() const { return spr->getFrame(); }

const Bitmap &Entity::nextForm() const { return spr->nextFrame(); }

const vector<int> &Entity::dimensions() const { return spriteFrame().getDimensions(); }

const vector<Action> &Entity::getActions() const { return acts; }

void Entity::setActions(const vector<Action> &inputs) {
    acts = inputs;
}

void Entity::addMovement(string s, unique_ptr<MovementComponent> m) {
    mvt->addMovement(s, std::move(m));
}

void Entity::removeMovement(string s) {
    mvt->removeMovement(s);
}

Posn &Entity::moveVelocity() {
    vel = mvt->getVelocity(*this);
    return vel;
}

Collider &Entity::getCollider() { return *col; }

void Entity::accept(Collider &v) { doAccept(v); }

void Entity::borderCollide(Border b) { doBorderCollide(b); }

void Entity::setVelocity(Posn v) { vel = v; }

void Entity::create() { doCreate(); }

void Entity::onTick() { doOnTick(); }