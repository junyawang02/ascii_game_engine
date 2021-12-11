#include "keyboard.h"
#include "../util/action.h"
#include "ncurses.h"
#include <map>

using std::map;

const map<int, Action> defaultMap {
    {'w', Action::UP},
    {'s', Action::DOWN},
    {'a', Action::LEFT},
    {'d', Action::RIGHT},
    {KEY_UP, Action::UP},
    {KEY_DOWN, Action::DOWN},
    {KEY_LEFT, Action::LEFT},
    {KEY_RIGHT, Action::RIGHT},
    {27, Action::ESCAPE}
};

Keyboard::Keyboard(): mapping{defaultMap} {}

Keyboard::Keyboard(map<int, Action> mapping): mapping{mapping} {}

Action Keyboard::action() {
    int c = getch();
	flushinp();
	return mapping[c];
}

void Keyboard::changeKey(int oldCmd, int newCmd) {
    mapping[newCmd] = mapping[oldCmd];
    mapping.erase(oldCmd);
}

void Keyboard::addAction(int cmd, Action act) {
    mapping[cmd] = act;
}
