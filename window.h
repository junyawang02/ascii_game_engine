#ifndef WINDOW_H
#define WINDOW_H

#include "ncurses.h"

class Window {
    WINDOW *theWindow; 

public:
    Window(int height, int width, int starty, int startx);
    WINDOW *getWindow();
};

#endif