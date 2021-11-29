#include "clientState.h"
#include "game.h"
#include "gameView.h"
#include "keyboard.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;

int main() {
    unique_ptr<Game> g = make_unique<Game>(make_unique<ClientState>());
    g->addController(make_unique<Keyboard>());
    g->addView(make_unique<GameView>(g.get()));
    g->go();
}