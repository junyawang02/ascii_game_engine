#include "walker.h"
#include "../../engine/movement/linear.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/myRandom.h"
#include "../collider/enemyCollider.h"
#include <memory>
#include <string>

using std::make_unique;

Walker::Walker(int x, int y) : Acceptor{x, y, make_unique<Still>(Bitmap{2, 2, 'a'}), make_unique<EnemyCollider>(this), 5},
                               changeDir{0}, dir{0} {}

void Walker::changeDirection() {
    changeDir = myRandom(3, 8);
    int newDir = myRandom(1, 4);
    while (newDir == dir) {
        newDir = myRandom(1, 4);
    }
    dir = newDir;
    if (dir == 1) {
        addMovement("base", make_unique<Linear>(0, -1));
    } else if (dir == 2) {
        addMovement("base", make_unique<Linear>(0, 1));
    } else if (dir == 3) {
        addMovement("base", make_unique<Linear>(-1, 0));
    } else {
        addMovement("base", make_unique<Linear>(1, 0));
    }
}

void Walker::doCreate() {
    changeDirection();
}

void Walker::doOnTick() {
    --changeDir;
    if (changeDir <= 0)
        changeDirection();
}
