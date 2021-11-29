#include "game.h"
// #include "clock.h"
#include "state.h"
#include <memory>
#include <iostream>
#include "action.h"

Game::Game(unique_ptr<State> s): theState{std::move(s)} {}

void Game::addState(unique_ptr<State> s) {
    theState = std::move(s);
}

void Game::loop() {
    while (playing) {
        // updateViews();
        // displayViews();
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