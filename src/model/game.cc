#include "game.h"
#include "../clock/clock.h"
#include "../state/state.h"
#include "../util/action.h"
#include "../util/line.h"
#include <memory>
#include <vector>
#include <string>

using std::unique_ptr;
using std::vector;

Game::Game(unique_ptr<State> s) : clock{Clock{}}, state{std::move(s)} {}

void Game::addState(unique_ptr<State> s) {
    state = std::move(s);
}

void Game::go() {
    if (state == nullptr)
        return;
    state->create();
    playing = true;
    updateViews();
    displayViews();

    while (playing) {
        if (clock.tick()) {
            ++numTick;
            vector<Action> inputs = getAllActions();
            state->updateActions(inputs);
            updateViews();
            // updateViews(l1, "Ticks passed:" + std::to_string(numTick));
            displayViews();
            state->onTick();
            if (inputs[0] == Action::ESCAPE)
                stop();
        }
    }
}

void Game::stop() {
    playing = false;
}

vector<pair<const Posn &, const Bitmap &>> Game::drawList() { return state->drawList(); }