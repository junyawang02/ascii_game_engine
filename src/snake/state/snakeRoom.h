#ifndef SNAKEROOM_H
#define SNAKEROOM_H

#include "../../engine/state/state.h"
#include <memory>

using std::unique_ptr;

class Game;
class Head;

class SnakeRoom : public State {
    int score;
    Head *head;
    void doCreate(Game &g) override;
    void doOnTick(Game &g) override;
    // void spawnFruit();

public:
    SnakeRoom();
};

#endif
