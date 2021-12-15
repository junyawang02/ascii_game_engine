#include "level1.h"
#include "level.h"
#include "../entity/enemy.h"
#include "../entity/walker.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

class Player;

int Level1::doGetNumber() { return 1; }

unique_ptr<Enemy> Level1::doGetEnemy(int x, int y, Player *p) {
    return make_unique<Walker>(x, y);
}
