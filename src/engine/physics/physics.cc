#include "physics.h"
#include "../entity/entity.h"
#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include "../util/border.h"
#include <cmath>
#include <list>
#include <map>
#include <vector>

using std::list;
using std::map;
using std::vector;

Physics::Physics(bool s) : solid{s} {}

void Physics::solidBorder(bool s) { solid = s; }

// iterative check through each cell of both bitmaps
bool Physics::checkCollisionHelp(Entity *ent, Entity *other) {
    const vector<Cell> &b1 = ent->spriteFrame().getBitmap();
    const vector<Cell> &b2 = other->spriteFrame().getBitmap();
    const Posn &p1 = ent->getPos();
    const Posn &p2 = other->getPos();

    for (auto cell1 : b1) {
        for (auto cell2 : b2) {
            if (p1 + cell1.p == p2 + cell2.p)
                return true; // if any of their cells overlap, true
        }
    }
    return false;
}

bool Physics::checkCollision(Entity *ent, Entity *other) {
    if (ent->getDestroy() || other->getDestroy()) // can't collide with destroyed entities
        return false;
    if (ent == other) // can't collide with self
        return false;
    if (ent->getPos() == other->getPos()) // very simple check
        return true;

    // simple dimension check
    const vector<int> &d1 = ent->dimensions();
    const vector<int> &d2 = other->dimensions();

    int minX1 = ent->getPos().x + d1[3];
    int minX2 = other->getPos().x + d2[3];
    int maxX1 = ent->getPos().x + d1[2];
    int maxX2 = other->getPos().x + d2[2];
    if (maxX1 >= minX2 && minX1 <= maxX2) // the x dimensions overlap, time for complex check
        return checkCollisionHelp(ent, other);

    int minY1 = ent->getPos().y + d1[0];
    int minY2 = other->getPos().y + d2[0];
    int maxY1 = ent->getPos().y + d1[1];
    int maxY2 = other->getPos().y + d2[1];
    if (maxY1 >= minY2 && minY1 <= maxY2)
        return checkCollisionHelp(ent, other);

    return false; // dimensions do not overlap, no collision
}

void Physics::stepHelp(Entity *ent, list<Entity *> &others) {
    Posn &vel = ent->moveVelocity();
    for (auto other : others) {
        if (checkCollision(ent, other)) {
            ent->accept(other->getCollider());
        }
    }
    borderCollision(ent);
    while (vel.x != 0) {
        ent->addX(vel.x / abs(vel.x)); // 1 step in the pos/neg direction
        vel.x -= vel.x / abs(vel.x);   // 1 step less to move
        for (auto other : others) {
            if (checkCollision(ent, other)) {
                ent->accept(other->getCollider());
            }
        }
        borderCollision(ent);
    }
    while (vel.y != 0) {
        ent->addY(vel.y / abs(vel.y));
        vel.y -= vel.y / abs(vel.y);
        for (auto other : others) {
            if (checkCollision(ent, other)) {
                ent->accept(other->getCollider());
            }
        }
        borderCollision(ent);
    }
}

bool Physics::inBounds(Entity *e) {
    if (getBorder(e) == Border::N) return true;
    return false;
}

Border Physics::getBorder(Entity *e) {
    const vector<int> &dim = e->dimensions();
    Posn pos = e->getPos();

    int minX = pos.x + dim[3];
    int maxX = pos.x + dim[2];
    int minY = pos.y + dim[0];
    int maxY = pos.y + dim[1];

    if (minX < 1) return Border::L;
    if (maxX > 78) return Border::R;
    if (minY < 1) return Border::U;
    if (maxY > 20) return Border::D;
    return Border::N;
}

void Physics::outOfBounds(Entity *e) {
    if (inBounds(e)) 
        e->resetCount();
    else
        e->decrementCount();
}

void Physics::borderCollision(Entity *e) {
    if (!solid) return;
    Border collided = getBorder(e);
    if (collided == Border::N) return;
    e->borderCollide(collided);
}

void Physics::step(list<Entity *> &entities) {
    for (auto &entity : entities) {
        stepHelp(entity, entities);
        if (!solid) outOfBounds(entity);
    }
}
