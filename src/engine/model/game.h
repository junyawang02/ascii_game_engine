#ifndef GAME_H
#define GAME_H

#include "../clock/clock.h"
#include "../state/state.h"
#include "model.h"
#include <memory>
#include <deque>

using std::unique_ptr;
using std::vector;
using std::deque;

class Game : public Model {
    Clock clock;
    deque<unique_ptr<State>> states;
    size_t numTick;
    bool playing;
    virtual void doEndState(bool win);

protected:
    void addState(unique_ptr<State> s);

public:
    Game();
    Game(deque<unique_ptr<State>> states);
    Game(unique_ptr<State> s);
    void go();
    void stop();
    vector<pair<const Posn &, const Bitmap &>> drawList();
    void endState(bool win);
};

#endif
