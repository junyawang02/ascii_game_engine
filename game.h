#ifndef GAME_H
#define GAME_H

// #include "clock.h"
#include "model.h"
#include "state.h"
#include <memory>

using std::unique_ptr;
using std::vector;

class Game : public Model {
    // unique_ptr<Clock> theClock;
    unique_ptr<State> theState;

protected:
    void addState(unique_ptr<State> s);

public:
    Game(vector<View> v, vector<Controller> c, unique_ptr<State> s);
    void go();
    void stop();
};

#endif