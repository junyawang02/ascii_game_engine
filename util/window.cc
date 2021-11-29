#include "window.h"
#include "ncurses.h"

Window::Window(int height, int width, int starty, int startx) : theWindow{newwin(height, width, starty, startx)} {}

WINDOW *Window::getWindow() { return theWindow; }

void Window::refreshWin() { wrefresh(theWindow); }

void Window::drawBorder() { wborder(theWindow, '|', '|', '-', '-', '+', '+', '+', '+'); }

void Window::updateLine(Line line, const string &text) {
    wmove(theWindow, static_cast<int>(line), 0);
    wclrtoeol(theWindow);
    wprintw(theWindow, text.c_str());
}
