#include "fire.h"
#include "../../engine/sprite/animated.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/myRandom.h"
#include "../collider/fireCollider.h"
#include "health.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;

Fire::Fire(int x, int y) : Acceptor{x, y, make_unique<Animated>(vector<Bitmap>{Bitmap{'x'}, Bitmap{'X'}}), make_unique<FireCollider>(this)} {}

void Fire::doOnTick() {
    nextForm();
    if (getDestroy() && myRandom(1, 3) == 2)
        addSpawn(make_unique<Health>(getPos().x, getPos().y));
}
