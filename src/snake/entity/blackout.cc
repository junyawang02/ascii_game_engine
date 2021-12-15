#include "blackout.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/myRandom.h"
#include "../movement/holdControl.h"
#include "tail.h"
#include <memory>

using std::make_unique;

Blackout::Blackout() : Acceptor{1, 1, make_unique<Still>(Bitmap{20, 78, '.'}),
                                    make_unique<Collider>(this)},
                           time{myRandom(1, 3)} {}

void Blackout::doOnTick() {
    --time;
    if (time <= 0)
        flagDestroy();
}
