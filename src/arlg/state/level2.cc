#include "level2.h"
#include "../../engine/util/myRandom.h"
#include "../entity/enemy.h"
#include "../entity/stalker.h"
#include "../entity/walker.h"
#include "level.h"
#include <memory>

using std::make_unique;
using std::unique_ptr;

class Player;

int Level2::doGetNumber() { return 2; }

unique_ptr<Enemy> Level2::doGetEnemy(int x, int y, Player *p) {
    int spawn = myRandom(1, 2);
    switch (spawn) {
    case 1:
        return make_unique<Walker>(x, y);
    case 2:
        return make_unique<Stalker>(x, y, p);
    default: // should not be reached
        return make_unique<Walker>(x, y);
    }
}
