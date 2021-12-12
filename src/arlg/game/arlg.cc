#include "arlg.h"
#include "../../engine/controller/keyboard.h"
#include "../../engine/model/game.h"
#include "../../engine/view/gameView.h"
#include "../../engine/util/action.h"
#include "../state/level1.h"
#include "../state/loss.h"
#include <deque>
#include <memory>
#include <stdlib.h>

using std::deque;
using std::make_unique;
using std::unique_ptr;

ARLG::ARLG() : Game{} {
    srand(time(0));
    // addState(make_unique<Level1>());
    addState(make_unique<Loss>());
    unique_ptr<Keyboard> k = make_unique<Keyboard>();
    k->addAction('w', Action::W);
    k->addAction('a', Action::A);
    k->addAction('s', Action::S);
    k->addAction('d', Action::D);
    addController(std::move(k));
    addView(make_unique<GameView>(this));
    go();
}
