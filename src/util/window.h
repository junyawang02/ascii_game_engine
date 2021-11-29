#ifndef WINDOW_H
#define WINDOW_H

#include "ncurses.h"
#include "line.h"
#include <string>

using std::string;

class Window {
    WINDOW *theWindow; 

public:
    Window(int height, int width, int starty, int startx);
    WINDOW *getWindow();
    void refreshWin();
    void drawBorder();
    void updateLine(Line line, const string &text);
};

#endif