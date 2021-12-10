#ifndef WINDOW_H
#define WINDOW_H

#include "ncurses.h"
#include "line.h"
#include <string>
#include "posn.h"

using std::string;

class Window {
    WINDOW *theWindow; 

public:
    Window(int height, int width, int starty, int startx);
    ~Window();
    WINDOW *getWindow();
    void refreshWin();
    void drawBorder();
    void updateLine(Line line, const string &text);
    void drawChar(const Posn &p, char c);
    void clear();
};

#endif