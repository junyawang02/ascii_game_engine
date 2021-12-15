#include "stalker.h"
#include "../../engine/movement/follow.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/myRandom.h"
#include "player.h"
#include "walker.h"
#include <memory>

using std::make_unique;

Stalker::Stalker(int x, int y, Player *p) : Enemy{x, y, make_unique<Still>(Bitmap{2, 2, 'b'}), make_unique<Follow>(p, 1), 2} {}

void Stalker::doOnTick() {
    if (getDestroy() && myRandom(1, 4) == 3)
        addSpawn(make_unique<Walker>(getPos().x, getPos().y));
}
