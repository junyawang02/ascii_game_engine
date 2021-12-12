#include "player.h"
#include "../../engine/movement/control.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/line.h"
#include "../../engine/util/posn.h"
#include "../collider/playerCollider.h"
#include "bullet.h"
#include <memory>
#include <string>

using std::make_unique;
using std::pair;
using std::string;

Player::Player(int x, int y, size_t c) : Acceptor{x, y, make_unique<Still>(Bitmap{'p'}),
                                                  make_unique<Control>(c),
                                                  make_unique<PlayerCollider>(this), 5},
                                         control{c} {}

void Player::doOnTick() {
    if (getActions()[control] == Action::W)
        addSpawn(make_unique<Bullet>(getPos(), 0, -2, 'O'));
    else if (getActions()[control] == Action::A)
        addSpawn(make_unique<Bullet>(getPos(), -2, 0, 'O'));
    else if (getActions()[control] == Action::S)
        addSpawn(make_unique<Bullet>(getPos(), 0, 2, 'O'));
    else if (getActions()[control] == Action::D)
        addSpawn(make_unique<Bullet>(getPos(), 2, 0, 'O'));
}

pair<bool, bool> Player::doEndState() {
    if (getDestroy())
        return pair<bool, bool>{true, false};
    else
        return pair<bool, bool>{false, false};
}

pair<Line, string> Player::doUpdateStatus() {
    string healthMessage = "Health: " + std::to_string(getHealth());
    return pair<Line, string>{Line::L1, healthMessage};
}
