#include "level2.h"
#include "level.h"
#include "../entity/enemy.h"
#include "../entity/walker.h"
#include "../entity/stalker.h"
#include "../../engine/util/myRandom.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

class Player;

int Level2::doGetNumber() { return 2; }

unique_ptr<Enemy> Level2::doGetEnemy(int x, int y, Player *p) {
    int spawn = myRandom(1,2);
    switch(spawn) {
        case 1:
            return make_unique<Walker>(x, y);
        case 2:
            return make_unique<Stalker>(x, y, p);
        default: // should not be reached
            return make_unique<Walker>(x, y);
    }
}
