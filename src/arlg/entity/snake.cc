#include "snake.h"
#include "../../engine/movement/linear.h"
#include "../../engine/sprite/animated.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/util/border.h"
#include "../../engine/util/myRandom.h"
#include "../collider/snakeCollider.h"
#include "enemy.h"
#include <memory>
#include <string>

using std::make_unique;

Snake::Snake(int x, int y, bool horizontal) : Enemy{x, y,
                                                    horizontal ? make_unique<Animated>(vector<Bitmap>{Bitmap{vector<Cell>{{0, 0, 'Z'}, {1, 0, 'z'}, {2, 0, 'z'}, {3, 0, 'z'}}}, Bitmap{vector<Cell>{{0, 0, 'Z'}, {-1, 0, 'z'}, {-2, 0, 'z'}, {-3, 0, 'z'}}}})
                                                               : make_unique<Animated>(vector<Bitmap>{Bitmap{vector<Cell>{{0, 0, 'Z'}, {0, 1, 'z'}, {0, 2, 'z'}, {0, 3, 'z'}}}, Bitmap{vector<Cell>{{0, 0, 'Z'}, {0, -1, 'z'}, {0, -2, 'z'}, {0, -3, 'z'}}}}),
                                                    make_unique<SnakeCollider>(this),
                                                    3},
                                              horizontal{horizontal} {}

void Snake::doCreate() {
    if (horizontal) {
        addMovement("base", make_unique<Linear>(0, 0));
    } else {
        addMovement("base", make_unique<Linear>(0, -1));
    }
}

void Snake::doBorderCollide(Border b) {
    switch (b) {
    case Border::U:
        addY(1);
        if (!horizontal) {
            addY(3);
            nextForm();
            addMovement("base", make_unique<Linear>(0, 1));
        }
        break;
    case Border::D:
        addY(-1);
        if (!horizontal) {
            addY(-3);
            nextForm();
            addMovement("base", make_unique<Linear>(0, -1));
        }
        break;
    case Border::R:
        addX(-1);
        if (horizontal) {
            addX(-3);
            nextForm();
            addMovement("base", make_unique<Linear>(-1, 0));
        }
        break;
    case Border::L:
        addX(1);
        if (horizontal) {
            addX(3);
            nextForm();
            addMovement("base", make_unique<Linear>(1, 0));
        }
        break;
    default:
        break;
    }
}