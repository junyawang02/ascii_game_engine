#include "head.h"
#include "../../engine/movement/holdControl.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../collider/headCollider.h"
#include <memory>

using std::make_unique;
using std::pair;

Head::Head(int x, int y) : Acceptor{x, y, make_unique<Still>(Bitmap{'S'}),
                                    make_unique<HoldControl>(c),
                                    make_unique<HeadCollider>(this)},
                           toGrow{false}, count{-1} {}

void doOnTick() {
    if (count > 0) {
        --count;
    } else if (count == 0) {
        flagDestroy();
    }
}

pair<bool, bool> Head::doEndState() {
    if (getDestroy())
        return pair<bool, bool>{true, false};
    else
        return pair<bool, bool>{false, false};
}

void Head::setGrow(bool g) { toGrow = g; }

bool Head::getGrow() { return toGrow; }

void Head::startCount() { count = 5; }
