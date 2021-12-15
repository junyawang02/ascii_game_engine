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

Game::Game(): clock{Clock{}} {}

Game::Game(deque<unique_ptr<State>> states) : clock{Clock{}}, states{std::move(states)} {}

Game::Game(unique_ptr<State> s) : clock{Clock{}} {
    addState(std::move(s));
}

void Game::doEndState(bool win) {
    popState(1);
}

void Game::addState(unique_ptr<State> s) {
    states.push_back(std::move(s));
}

void Game::popState(size_t n) {
    size_t popped = 0;
    while (!states.empty() && popped < n) {
        states.pop_front();
        ++popped;
    }
    go();
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
    clearViews();
    doEndState(win);
    if (states.empty())
        stop();
}

void Game::stop() {
    playing = false;
}

vector<pair<const Posn &, const Bitmap &>> Game::drawList() { return states[0]->drawList(); }

size_t Game::numStates() { return states.size(); }