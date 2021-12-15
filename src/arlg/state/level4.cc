#include "../../engine/util/myRandom.h"
#include "../entity/enemy.h"
#include "../entity/snake.h"
#include "../entity/stalker.h"
#include "level.h"
#include "level4.h"
#include <memory>

using std::make_unique;
using std::unique_ptr;

class Player;

int Level4::doGetNumber() { return 4; }

unique_ptr<Enemy> Level4::doGetEnemy(int x, int y, Player *p) {
    int spawn = myRandom(1, 2);
    bool horizontal = myRandom(0, 1);
    switch (spawn) {
    case 1:
        return make_unique<Snake>(x, y, horizontal);
    case 2:
        return make_unique<Stalker>(x, y, p);
    default: // should not be reached
        return make_unique<Stalker>(x, y, p);
    }
}
