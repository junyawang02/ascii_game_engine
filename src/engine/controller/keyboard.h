#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "controller.h"
#include "ncurses.h"
#include "../util/action.h"
#include <map>

using std::map;

class Keyboard : public Controller {
    map<int, Action> mapping;

    Action action() override;

public:
    Keyboard();
    Keyboard(map<int, Action> mapping);
    void remap(int oldCmd, int newCmd);
};

#endif
