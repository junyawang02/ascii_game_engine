#include "clientState.h"
#include "game.h"
#include "gameView.h"
#include "keyboard.h"
#include <memory>
#include <vector>
#include <iostream>

using std::make_unique;
using std::vector;

int main() {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();

    unique_ptr<Game> g = make_unique<Game>(make_unique<ClientState>());
    g->addController(make_unique<Keyboard>());
    g->addView(make_unique<GameView>(g.get()));
    g->go();

    endwin();
}