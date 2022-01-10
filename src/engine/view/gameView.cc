#include "gameView.h"
#include "../model/game.h"
#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include "../util/window.h"
#include "ncurses.h"
#include <memory>
#include <string>

using std::make_unique;
using std::string;
using std::unique_ptr;

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

void GameView::doUpdate() {
    screen->clear();
    auto drawList = theGame->drawList();
    for (auto &d : drawList)
        drawBitmap(d.first, d.second);
    screen->drawBorder();
}

void GameView::doUpdate(Line line, string text) {
    status->updateLine(line, text);
}

void GameView::doClear() {
    screen->clear();
    status->clear();
}

void GameView::doDisplayView() {
    screen->refreshWin();
    status->refreshWin();
}

void GameView::drawBitmap(const Posn &p, const Bitmap &b) {
    for (auto cell : b.getBitmap()) {
        Posn loc = p + cell.p;
        screen->drawChar(loc, cell.c);
    }
}
