#include "window.h"
#include "ncurses.h"
#include "posn.h"

Window::Window(int height, int width, int starty, int startx) : theWindow{newwin(height, width, starty, startx)} {}

Window::~Window() { delwin(theWindow); }

WINDOW *Window::getWindow() { return theWindow; }

void Window::refreshWin() { wrefresh(theWindow); }

void Window::drawBorder() { wborder(theWindow, '|', '|', '-', '-', '+', '+', '+', '+'); }

void Window::updateLine(Line line, string text) {
    wmove(theWindow, static_cast<int>(line), 0);
    wclrtoeol(theWindow);
    wprintw(theWindow, text.c_str());
}

void Window::drawChar(const Posn &p, char c) {
    mvwaddch(theWindow, p.y, p.x, c);
}

void Window::clear() {
    werase(theWindow);
}
