#include "arlg.h"
#include "../../engine/controller/keyboard.h"
#include "../../engine/model/game.h"
#include "../../engine/util/action.h"
#include "../../engine/view/gameView.h"
#include "../state/level1.h"
#include "../state/level2.h"
#include "../state/level3.h"
#include "../state/level4.h"
#include "../state/level5.h"
#include "../state/bossRoom.h"
#include "../state/loss.h"
#include "../state/win.h"
#include <deque>
#include <memory>
#include <stdlib.h>

using std::deque;
using std::make_unique;
using std::unique_ptr;

ARLG::ARLG() : Game{} {
    srand(time(0));
    addState(make_unique<Level1>());
    addState(make_unique<Level2>());
    addState(make_unique<Level3>());
    addState(make_unique<Level4>());
    addState(make_unique<Level5>());
    addState(make_unique<BossRoom>());
    addState(make_unique<Win>());
    addState(make_unique<Loss>());
    unique_ptr<Keyboard> k = make_unique<Keyboard>();
    k->addAction('w', Action::W);
    k->addAction('a', Action::A);
    k->addAction('s', Action::S);
    k->addAction('d', Action::D);
    addController(std::move(k));
    addView(make_unique<GameView>(this));
}

void ARLG::skipToLevel(int n) {
    popState(n - 1);
}

void ARLG::doEndState(bool win) {
    if (numStates() == 2) {
        // on win screen, skip loss
        popState(2);
    } else if (!win) {
        // go to loss scren
        popState(numStates() - 1);
    } else {
        popState(1);
    }
}
