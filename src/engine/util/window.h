#ifndef WINDOW_H
#define WINDOW_H

#include "line.h"
#include "ncurses.h"
#include "posn.h"
#include <string>

using std::string;

class Window {
    WINDOW *theWindow;

public:
    Window(int height, int width, int starty, int startx);
    ~Window();
    void refreshWin();
    void drawBorder();
    void updateLine(Line line, string text);
    void drawChar(const Posn &p, char c);
    void clear();
};

#endif