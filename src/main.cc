#include "arlg/state/level1.h"
#include "engine/controller/keyboard.h"
#include "engine/model/game.h"
#include "engine/view/gameView.h"
#include <memory>
#include <vector>
#include <stdlib.h>

using std::make_unique;
using std::vector;

int main() {
    srand(time(0));
    unique_ptr<State> s = make_unique<Level1>();
    unique_ptr<Game> g = make_unique<Game>(std::move(s));
    g->addController(make_unique<Keyboard>());
    g->addView(make_unique<GameView>(g.get()));
    g->go();
}