#include "physics.h"
#include "../entity/entity.h"
#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include "border.h"
// #include "solidBorder.h"
#include "viewBorder.h"
#include <cmath>
#include <list>
#include <map>
#include <memory>
#include <ncurses.h>
#include <vector>

using std::list;
using std::make_unique;
using std::map;
using std::unique_ptr;
using std::vector;

// Physsics::Physics(bool solid) : bor{solid ? make_unique<SolidBorder>() : make_uniqe<ViewBorder>()} {}

Physics::Physics(unique_ptr<Border> b) : bor{std::move(b)} {}

// void Physics::solidBorder(bool solid) {
//     bor = solid ? make_unique<SolidBorder>() : make_unique<ViewBorder>()
// }

void Physics::setBorder(unique_ptr<Border> b) { bor = std::move(b); }

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

void Physics::stepHelp(Entity *ent, Posn vel, list<Entity *> &others) {
    int x = vel.x;
    int y = vel.y;
    for (auto other : others) {
        if (checkCollision(ent, other)) {
            printw("fuck");
            refresh();
        }
    }
    while (x != 0) {
        ent->addX(x / abs(x)); // 1 step in the pos/neg direction
        x -= x / abs(x);       // 1 step less to move
        for (auto other : others) {
            if (checkCollision(ent, other)) {
                printw("fuck");
                refresh();
            }
        }
    }
    while (y != 0) {
        ent->addY(y / abs(y));
        y -= y / abs(y);
    }
}

void Physics::step(list<Entity *> &entities) {
    for (auto &entity : entities) {
        stepHelp(entity, entity->moveVelocity(), entities);
        bor->borderStep(entity);
    }
}
