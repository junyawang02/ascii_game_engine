#include "game.h"
// #include "clock.h"
#include "state.h"
#include <memory>

Game::Game(vector<View> v, vector<Controller> c, State s): Model{v, c}, theState{std::move(s)} {}

void Game::addState(unique_ptr<State> s) {
    theState = std::move(s);
}

void Game::go() {
    if (theState == nullptr)
        return;
    theState->create();
}

void Game::stop() {
}