#include "level3.h"
#include "level.h"
#include "../entity/enemy.h"
#include "../entity/walker.h"
#include "../entity/popup.h"
#include "../../engine/util/myRandom.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

class Player;

int Level3::doGetNumber() { return 3; }

unique_ptr<Enemy> Level3::doGetEnemy(int x, int y, Player *p) {
    int spawn = myRandom(1,2);
    switch(spawn) {
        case 1:
            return make_unique<Walker>(x, y);
        case 2:
            return make_unique<Popup>(x, y);
        default: // should not be reached
            return make_unique<Walker>(x, y);
    }
}
