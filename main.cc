#include "game.h"
#include "clientState.h"
#include "keyboard.h"
#include "gameView.h"
#include <memory>

using std::make_unique;

int main() {
    Game g{};
    g.addState(make_unique<ClientState>());
    g.addController(make_unique<Keyboard>());
    g.addView(make_unique<GameView>(*g));
    g.go();
}