#include "gameView.h"
#include "../util/window.h"
#include "ncurses.h"
#include <string>

using std::make_unique;
using std::string;
using std::unique_ptr;

class Game;

GameView::GameView(Game *g) : View{}, theGame{g} {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();
    screen = make_unique<Window>(22, 80, 0, 0);
    status = make_unique<Window>(3, 80, 22, 0);
    screen->drawBorder();
}

GameView::~GameView() { endwin(); }

void GameView::update() {
    screen->drawBorder();
}

void GameView::update(Line line, const string &text) {
    status->updateLine(line, text);
}

void GameView::displayView() {
    screen->refreshWin();
    status->refreshWin();
}