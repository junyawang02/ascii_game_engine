#include "state.h"
#include "../entity/entity.h"
#include "../physics/physics.h"
#include "../sprite/bitmap.h"
#include "../util/action.h"
#include "../util/posn.h"
#include <list>
#include <memory>
#include <vector>

using std::list;
using std::pair;
using std::unique_ptr;
using std::vector;

State::State(unique_ptr<Physics> p) : phys{std::move(p)} {}

void State::create() {
    for (auto &level : entities)
        for (auto &entity : level.second)
            entity->create();
    doCreate();
}

void State::onTick() {
    for (auto &level : entities) {
        for (auto it = level.second.begin(); it != level.second.end(); ++it) {
            (*it)->onTick();
            if ((*it)->getDestroy())
                it = level.second.erase(it);
        }
    }
    for (auto &level : entities) {
        list<Entity *> entityList;
        for (auto &entity : level.second) {
            entityList.push_back(entity.get());
        }
        phys->step(entityList);
    }
    doOnTick();
}

void State::addEntity(int height, unique_ptr<Entity> e) {
    entities[height].emplace_back(std::move(e));
}

void State::addEntities(int height, list<unique_ptr<Entity>> &ents) {
    for (auto &e : ents)
        entities[height].emplace_back(std::move(e));
}

void State::updateActions(const vector<Action> &inputs) {
    for (auto &level : entities)
        for (auto &entity : level.second)
            entity->setActions(inputs);
}

bool State::checkCollisions(Entity *e, list<Entity*> others) {
    for (auto other: others)
        if (phys->checkCollision(e, other) || !phys->inBounds(e)) return true;
    return false;
}

vector<pair<const Posn &, const Bitmap &>> State::drawList() {
    vector<pair<const Posn &, const Bitmap &>> v;
    for (auto &level : entities)
        for (auto &entity : level.second)
            v.push_back(pair<const Posn &, const Bitmap &>{entity->getPos(), entity->spriteFrame()});
    return v;
}
