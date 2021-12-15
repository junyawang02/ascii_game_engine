#include "snake.h"
#include "../../engine/controller/keyboard.h"
#include "../../engine/model/game.h"
#include "../../engine/util/action.h"
#include "../../engine/view/gameView.h"
#include "../state/snakeRoom.h"
#include <memory>
#include <stdlib.h>

using std::make_unique;
using std::unique_ptr;

Snake::Snake() : Game{} {
    srand(time(0));
    addState(make_unique<SnakeRoom>());
    addController(make_unique<Keyboard>());
    addView(make_unique<GameView>(this));
}
