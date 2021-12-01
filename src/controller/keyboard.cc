#include "keyboard.h"
#include "../util/action.h"
#include "ncurses.h"
#include <map>

using std::map;

const map<int, Action> defaultMap {
    {'w', Action::UP},
    {'d', Action::DOWN},
    {'s', Action::LEFT},
    {'a', Action::RIGHT},
    {KEY_UP, Action::UP},
    {KEY_RIGHT, Action::DOWN},
    {KEY_DOWN, Action::LEFT},
    {KEY_LEFT, Action::RIGHT}
};

Keyboard::Keyboard(): mapping{defaultMap} {}

Keyboard::Keyboard(map<int, Action> mapping): mapping{mapping} {}

Action Keyboard::action() {
    int c = getch();
	flushinp();
	return mapping[c];
}

void Keyboard::remap(int oldCmd, int newCmd) {
    mapping[newCmd] = mapping[oldCmd];
    mapping.erase(oldCmd);
}
