#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include "../util/window.h"
#include "view.h"
#include <string>
#include <memory>

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
    void drawBitmap(const Posn &p, const Bitmap &b);
};

#endif