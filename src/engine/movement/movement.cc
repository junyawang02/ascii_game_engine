#include "movement.h"
#include "../util/posn.h"
#include <map>
#include <memory>
#include <string>

using std::map;
using std::string;
using std::unique_ptr;

class Entity;

Movement::Movement() {}

Movement::Movement(unique_ptr<MovementComponent> base) {
    moveMap.emplace("base", std::move(base));
}

Posn Movement::velocity(const Entity &e) {
    Posn total{0, 0};
    for (auto &p : moveMap) {
        total += p.second->getVelocity(e);
    }
    return total;
}

void Movement::addMovement(string s, unique_ptr<MovementComponent> mov) {
    moveMap[s] = std::move(mov);
}

void Movement::removeMovement(string s) {
    moveMap.erase(s);
}

void Movement::clearMovement() {
    moveMap.clear();
}
