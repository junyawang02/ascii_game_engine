#ifndef GAME_H
#define GAME_H

#include "../clock/clock.h"
#include "../state/state.h"
#include "model.h"
#include <memory>

using std::unique_ptr;
using std::vector;

class Game : public Model {
    Clock theClock;
    unique_ptr<State> theState;
    bool playing;

protected:
    void addState(unique_ptr<State> s);

public:
    Game(unique_ptr<State> s);
    void go();
    void stop();
    vector<pair<const Posn &, const Bitmap &>> drawList();
};

#endif
