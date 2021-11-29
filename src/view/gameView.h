#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <memory>

#include "view.h"
#include "../util/window.h"
#include <string>

using std::string;
using std::unique_ptr;

class Game;

class GameView : public View {
    Game *theGame;
    unique_ptr<Window> screen;
    unique_ptr<Window> status;

public:
    GameView(Game *g);
    ~GameView();
    void update() override;
    void update(Line line, const string &text) override;
    void displayView() override;
};

#endif