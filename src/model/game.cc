#include "game.h"
#include "../clock/clock.h"
#include "../state/state.h"
#include "../util/action.h"
#include <iostream>
#include <memory>

Game::Game(unique_ptr<State> s) : theClock{Clock{}}, theState{std::move(s)} {}

void Game::addState(unique_ptr<State> s) {
    theState = std::move(s);
}

void Game::go() {
    if (theState == nullptr)
        return;
    theState->create();
    playing = true;
    updateViews();
    displayViews();

    while (playing) {
        if (theClock.tick()) {
            updateViews();
            displayViews();
            theState->onTick();
            if (getAction(0) == Action::UP)
                stop();
        }
    }
}

void Game::stop() {
    playing = false;
}

vector<pair<const Posn &, const Bitmap &>> Game::drawList() { return theState->drawList(); }