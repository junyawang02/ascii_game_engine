#include "../../engine/util/myRandom.h"
#include "../entity/enemy.h"
#include "../entity/snake.h"
#include "../entity/stalker.h"
#include "../entity/walker.h"
#include "../entity/popup.h"
#include "level.h"
#include "level5.h"
#include <memory>

using std::make_unique;
using std::unique_ptr;

class Player;

int Level5::doGetNumber() { return 5; }

unique_ptr<Enemy> Level5::doGetEnemy(int x, int y, Player *p) {
    int spawn = myRandom(1, 4);
    bool horizontal = myRandom(0, 1);
    switch (spawn) {
    case 1:
        return make_unique<Snake>(x, y, horizontal);
    case 2:
        return make_unique<Stalker>(x, y, p);
    case 3:
        return make_unique<Walker>(x, y);
    case 4:
        return make_unique<Popup>(x, y);
    default: // should not be reached
        return make_unique<Stalker>(x, y, p);
    }
}
