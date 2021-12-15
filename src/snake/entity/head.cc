#include "head.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../collider/headCollider.h"
#include "../movement/holdControl.h"
#include "tail.h"
#include <memory>

using std::make_unique;
using std::pair;

Head::Head(int x, int y) : Acceptor{x, y, make_unique<Still>(Bitmap{'S'}),
                                    make_unique<HoldControl>(0),
                                    make_unique<HeadCollider>(this)},
                           toGrow{false}, dead{false}, count{4} {}

void Head::doOnTick() {
    if (dead)
        --count;
    if (count < 0)
        flagDestroy();
    if (getPos().x + getPastVelocity().x < 1 || getPos().x + getPastVelocity().x > 78 ||
    getPos().y + getPastVelocity().y < 1 || getPos().y + getPastVelocity().y > 20)
        startCount();
}

pair<bool, bool> Head::doEndState() {
    if (getDestroy())
        return pair<bool, bool>{true, false};
    else
        return pair<bool, bool>{false, false};
}

void Head::setGrow(bool g) { toGrow = g; }

bool Head::getGrow() { return toGrow; }

void Head::startCount() {
    dead = true;
    clearMovement();
    for (auto &t : tail)
        t->clearMovement();
}

vector<Tail *> &Head::getTail() { return tail; }

void Head::addTail(Tail *t) { tail.push_back(t); }
