#ifndef GAME_H
#define GAME_H

// #include "clock.h"
#include "model.h"
#include "../state/state.h"
#include <memory>

using std::unique_ptr;
using std::vector;

class Game : public Model {
    // unique_ptr<Clock> theClock;
    bool playing;
    unique_ptr<State> theState;

    void loop();

protected:
    void addState(unique_ptr<State> s);

public:
    Game(unique_ptr<State> s);
    void go();
    void stop();
    vector<pair<const Posn &, const Bitmap &>> drawList();
};

#endif