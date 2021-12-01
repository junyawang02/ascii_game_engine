#include "state.h"
#include "../entity/entity.h"
#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include <memory>
#include <vector>

using std::pair;
using std::unique_ptr;
using std::vector;

void State::create() {
    for (auto &e : entities)
        e->create();
    doCreate();
}

void State::onTick() {
    for (auto &e : entities)
        e->onTick();
    doOnTick();
}

void State::addEntity(unique_ptr<Entity> e) {
    entities.push_back(std::move(e));
}

vector<pair<const Posn &, const Bitmap &>> State::drawList() {
    vector<pair<const Posn &, const Bitmap &>> v;
    for (auto &e : entities) {
        v.push_back(pair<const Posn &, const Bitmap &>{e->getPos(), e->spriteFrame()});
    }
    return v;
}
