#include "gameView.h"
#include "window.h"
#include "ncurses.h"
#include <string>
#include <iostream>

using std::make_unique;
using std::string;
using std::unique_ptr;

class Game;

GameView::GameView(Game *g) : theGame{g}, screen{make_unique<Window>(22, 80, 0, 0)}, status{make_unique<Window>(3, 80, 22, 0)} {
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();
    screen->drawBorder();
}

GameView::~GameView() {endwin();}

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