#include "game.h"
#include "../clock/clock.h"
#include "../state/state.h"
#include "../util/action.h"
#include "../util/line.h"
#include <deque>
#include <memory>
#include <string>
#include <vector>

using std::deque;
using std::unique_ptr;
using std::vector;

Game::Game(deque<unique_ptr<State>> states) : clock{Clock{}}, states{std::move(states)}, numTick{0} {}

Game::Game(unique_ptr<State> s) : clock{Clock{}} {
    addState(std::move(s));
}

void Game::doEndState(bool win) {
    states.pop_front();
}

void Game::addState(unique_ptr<State> s) {
    states.push_back(std::move(s));
}

void Game::go() {
    if (states.empty())
        return;
    states[0]->create(*this);
    playing = true;
    updateViews();
    displayViews();

    while (playing) {
        if (clock.tick()) {
            ++numTick;
            vector<Action> inputs = getAllActions();
            states[0]->updateActions(inputs);
            updateViews();
            displayViews();
            states[0]->onTick(*this);
            if (inputs[0] == Action::ESCAPE)
                stop();
        }
    }
}

void Game::endState(bool win) {
    doEndState(win);
    if (states.empty())
        stop();
}

void Game::stop() {
    playing = false;
}

vector<pair<const Posn &, const Bitmap &>> Game::drawList() { return states[0]->drawList(); }
