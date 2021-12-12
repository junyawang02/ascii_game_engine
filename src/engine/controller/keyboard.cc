#include "keyboard.h"
#include "../util/action.h"
#include <map>
#include <ncurses.h>

using std::map;

const map<int, Action> defaultMap{
    {'w', Action::UP},
    {'s', Action::DOWN},
    {'a', Action::LEFT},
    {'d', Action::RIGHT},
    {KEY_UP, Action::UP},
    {KEY_DOWN, Action::DOWN},
    {KEY_LEFT, Action::LEFT},
    {KEY_RIGHT, Action::RIGHT},
    {27, Action::ESCAPE},
    {ERR, Action::NONE},
};

Keyboard::Keyboard() : mapping{defaultMap} { setlocale(LC_ALL, ""); }

Keyboard::Keyboard(map<int, Action> mapping) : mapping{mapping} { setlocale(LC_ALL, ""); }

Action Keyboard::action() {
    int c = getch();
    flushinp();
    if (mapping.count(c))
        return mapping[c];
    return Action::INVALID;
}

void Keyboard::changeKey(int oldCmd, int newCmd) {
    mapping[newCmd] = mapping[oldCmd];
    mapping.erase(oldCmd);
}

void Keyboard::addAction(int cmd, Action act) {
    mapping[cmd] = act;
}
