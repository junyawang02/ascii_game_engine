#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "action.h"
#include "controller.h"
#include "ncurses.h"
#include <map>

using std::map;
using std::string;

class Keyboard : public Controller {
    std::map<int, Action> mapping;

    Action action() override;

public:
    Keyboard();
    void remap(int oldCmd, int newCmd);
};

#endif
