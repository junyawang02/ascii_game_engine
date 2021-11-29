#include "window.h"
#include "ncurses.h"

Window::Window(int height, int width, int starty, int startx): theWindow{newwin(height, width, starty, startx)} {}

WINDOW *Window::getWindow() { return theWindow; }