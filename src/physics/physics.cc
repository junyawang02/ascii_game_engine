#include "physics.h"
#include "../entity/entity.h"
#include "../util/posn.h"
#include "border.h"
// #include "solidBorder.h"
#include "viewBorder.h"
#include <list>
#include <map>
#include <memory>
#include <cmath>

using std::list;
using std::make_unique;
using std::map;
using std::unique_ptr;

// Physsics::Physics(bool solid) : bor{solid ? make_unique<SolidBorder>() : make_uniqe<ViewBorder>()} {}

Physics::Physics(unique_ptr<Border> b) : bor{std::move(b)} {}

// void Physics::solidBorder(bool solid) {
//     bor = solid ? make_unique<SolidBorder>() : make_unique<ViewBorder>()
// }

void Physics::setBorder(unique_ptr<Border> b) { bor = std::move(b); }

void Physics::stepHelp(Entity *ent, Posn vel, list<Entity *> &others) {
    int x = vel.x;
    int y = vel.y;
    while (x != 0) {
        ent->addX(x / abs(x)); // 1 step in the pos/neg direction
        x -= x / abs(x); // 1 step less to move
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
