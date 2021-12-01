#include "controller/keyboard.h"
#include "entity/clientEntity.h"
#include "model/game.h"
#include "sprite/bitmap.h"
#include "sprite/still.h"
#include "state/clientState.h"
#include "view/gameView.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;

int main() {
    unique_ptr<State> s = make_unique<ClientState>();
    s->addEntity(make_unique<ClientEntity>(1, 1, make_unique<Still>(Bitmap{'c'})));
    s->addEntity(make_unique<ClientEntity>(2, 5, make_unique<Still>(Bitmap{10, 5, 'w'})));
    unique_ptr<Game> g = make_unique<Game>(std::move(s));
    g->addController(make_unique<Keyboard>());
    g->addView(make_unique<GameView>(g.get()));
    g->go();
}