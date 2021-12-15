#include "boss.h"
#include "../../engine/movement/gravitate.h"
#include "../../engine/movement/linear.h"
#include "../../engine/movement/gravitate.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/animated.h"
#include "../../engine/util/myRandom.h"
#include "../../engine/util/border.h"
#include "stalker.h"
#include "walker.h"
#include "popup.h"
#include "snake.h"
#include "sprites.h"
#include "../collider/bossCollider.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;
using std::pair;

class Player;

Boss::Boss(int x, int y, Player *p) : Enemy{x, y, make_unique<Animated>(vector<Bitmap>{Bitmap{SPRITES::boss}, Bitmap{SPRITES::bossAngry}}), make_unique<BossCollider>(this), 20}, player{p}, angry{false} {}

void Boss::doCreate() {
    addMovement("linear", make_unique<Linear>(2, 1));
}

void Boss::doOnTick() {
    int spawn = myRandom(1, 40);
    int offset = myRandom(-2, 2);
    int horizontal = myRandom(0, 1);
    Posn pos = getPos();
    if (spawn == 1)
        addSpawn(make_unique<Walker>(pos.x + offset, pos.y - offset));
    else if (spawn == 2)
        addSpawn(make_unique<Stalker>(pos.x + offset, pos.y - offset, player));
    else if (spawn == 3 && angry)
        addSpawn(make_unique<Popup>(pos.x + offset, pos.y - offset));
    else if (spawn == 4 && angry)
        addSpawn(make_unique<Snake>(pos.x + offset, pos.y - offset, horizontal));

    if (getDestroy() && !angry) {
        setDestroy(false);
        addHealth(30);
        angry = true;
        nextForm();
        Posn vel = getVelocity();
        addMovement("linear", make_unique<Linear>(vel.x * 2, vel.y));
    }
}

void Boss::changeDirection() {
    Posn vel = getVelocity();
    addMovement("linear", make_unique<Linear>(-vel.x, -vel.y));
}

void Boss::doBorderCollide(Border b) {
    Posn vel = getVelocity();
    switch (b) {
    case Border::U:
        addY(1);
        setVelocity(Posn{0, 0});
        addMovement("linear", make_unique<Linear>(vel.x, vel.y * -1));
        break;
    case Border::D:
        addY(-1);
        setVelocity(Posn{0, 0});
        addMovement("linear", make_unique<Linear>(vel.x, vel.y * -1));
        break;
    case Border::R:
        addX(-1);
        setVelocity(Posn{0, 0});
        addMovement("linear", make_unique<Linear>(vel.x * -1, vel.y));
        break;
    case Border::L:
        addX(1);
        setVelocity(Posn{0, 0});
        addMovement("linear", make_unique<Linear>(vel.x * -1, vel.y));
        break;
    default:
        break;
    }
}

pair<Line, string> Boss::doUpdateStatus() {
    if (angry) {
        const string angerMessage = "The boss is enraged!";
        return pair<Line, string>{Line::L3, angerMessage};
    } 
    const string peaceMessage = "The boss is happy. But you must defeat it because this is a game.";
    return pair<Line, string>{Line::L3, peaceMessage};
}

pair<bool, bool> Boss::doEndState() {
    if (getDestroy())
        return pair<bool, bool>{true, true};
    else
        return pair<bool, bool>{false, false};
}