#include "state.h"
#include "../entity/entity.h"
#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include "../physics/physics.h"
#include <memory>
#include <vector>
#include <list>

using std::pair;
using std::unique_ptr;
using std::vector;
using std::list;

State::State(unique_ptr<Physics> p): phys{std::move(p)} {}

void State::create() {
    for (auto &entry : entities)
        for (auto &entity : entry.second)
            entity->create();
    doCreate();
}

void State::onTick() {
    phys->step(entities);
    for (auto &entry : entities)
        for (auto it = entry.second.begin() ; it != entry.second.end() ; ++it) {
            (*it)->onTick();
            if ((*it)->getDestroy())
                it = entry.second.erase(it);
        }
    doOnTick();
}

void State::addEntity(int height, unique_ptr<Entity> e) {
    entities[height].emplace_back(std::move(e));
}

vector<pair<const Posn &, const Bitmap &>> State::drawList() {
    vector<pair<const Posn &, const Bitmap &>> v;
    for (auto &entry : entities)
        for (auto &entity : entry.second)
            v.push_back(pair<const Posn &, const Bitmap &>{entity->getPos(), entity->spriteFrame()});
    return v;
}
