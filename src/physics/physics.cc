#include "physics.h"
#include "../entity/entity.h"
#include "../util/posn.h"
#include "border.h"
// #include "solidBorder.h"
#include "viewBorder.h"
#include <map>
#include <memory>
#include <list>

using std::make_unique;
using std::map;
using std::unique_ptr;
using std::list;

// Physsics::Physics(bool solid) : bor{solid ? make_unique<SolidBorder>() : make_uniqe<ViewBorder>()} {}

Physics::Physics(unique_ptr<Border> b) : bor{std::move(b)} {}

// void Physics::solidBorder(bool solid) {
//     bor = solid ? make_unique<SolidBorder>() : make_unique<ViewBorder>()
// }

void Physics::setBorder(unique_ptr<Border> b) { bor = std::move(b); }

void Physics::step(map<int, list<unique_ptr<Entity>>> &entities) {
    for (auto &entry : entities)
        for (auto &entity : entry.second) {
            entity->setPos(entity->getPos() + entity->moveVelocity());
            bor->borderStep(entity.get());
        }
}
