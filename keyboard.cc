#include "keyboard.h"
#include "action.h"
#include <map>

Keyboard::Keyboard() {
    setlocale(LC_ALL, "");
    mapping['w'] = Action::UP;
    mapping['d'] = Action::RIGHT;
    mapping['s'] = Action::DOWN;
    mapping['a'] = Action::LEFT;
    mapping[KEY_UP] = Action::UP;
    mapping[KEY_RIGHT] = Action::RIGHT;
    mapping[KEY_DOWN] = Action::DOWN;
    mapping[KEY_LEFT] = Action::LEFT;
}

Action Keyboard::action() {
    int n;
    while ((n = getch()) == ERR)
        continue;

    if (mapping.find(n) != mapping.end()) {
        return mapping[n];
    }
    return Action::INVALID;
}

void Keyboard::remap(int oldCmd, int newCmd) {
    mapping[newCmd] = mapping[oldCmd];
    mapping.erase(oldCmd);
}
