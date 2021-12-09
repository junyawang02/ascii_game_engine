#include "client/clientEntity.h"
#include "client/clientState.h"
#include "controller/keyboard.h"
#include "model/game.h"
#include "sprite/bitmap.h"
#include "sprite/still.h"
#include "view/gameView.h"
#include "physics/physics.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;

int main() {
    unique_ptr<State> s = make_unique<ClientState>(make_unique<Physics>(true));
    unique_ptr<Game> g = make_unique<Game>(std::move(s));
    g->addController(make_unique<Keyboard>());
    g->addView(make_unique<GameView>(g.get()));
    g->addView(make_unique<GameView>(g.get()));
    g->go();
}