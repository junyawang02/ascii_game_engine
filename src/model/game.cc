#include "game.h"
// #include "clock.h"
#include "../state/state.h"
#include "../util/action.h"
#include <iostream>
#include <memory>

Game::Game(unique_ptr<State> s) : theState{std::move(s)} {}

void Game::addState(unique_ptr<State> s) {
    theState = std::move(s);
}

void Game::loop() {
    while (playing) {
        updateViews();
        displayViews();
        if (getAction(0) == Action::UP)
            stop();
    }
}

void Game::go() {
    if (theState == nullptr)
        return;
    theState->create();
    playing = true;
    updateViews();
    displayViews();
    loop();
}

void Game::stop() {
    playing = false;
}

vector<pair<const Posn &, const Bitmap &>> Game::drawList() { return theState->drawList(); }