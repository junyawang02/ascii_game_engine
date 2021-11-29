#include "gameView.h"
#include "window.h"
#include <ncurses.h>
#include <string>

using std::make_unique;
using std::string;
using std::unique_ptr;

class Game;

GameView::GameView(Game *g) : theGame{g}, screen{make_unique<Window>(22, 80, 0, 0)}, status{make_unique<Window>(3, 80, 22, 0)} {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    wborder(screen->getWindow(), '|', '|', '-', '-', '+', '+', '+', '+');
}

GameView::~GameView(){ endwin(); }

void GameView::update() {
    wrefresh(screen->getWindow());
}

void GameView::update(Line line, const string &text) {
    wmove(status->getWindow(), static_cast<int>(line), 0);
    wclrtoeol(status->getWindow());
    wprintw(status->getWindow(), text.c_str());
    wrefresh(status->getWindow());
}

void GameView::displayView() { refresh(); }