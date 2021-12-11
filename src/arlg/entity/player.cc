#include "player.h"
#include "../../engine/movement/control.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../collider/playerCollider.h"
#include "../../engine/util/line.h"
#include <memory>
#include <string>

using std::make_unique;
using std::pair;
using std::string;

Player::Player(int x, int y, size_t c) : 
    Acceptor {x, y, make_unique<Still>(Bitmap{'p'}), 
                    make_unique<Control>(c),
                    make_unique<PlayerCollider>(this), 5}, 
    control{c} {}

void Player::doCreate() {
    return;
}

void Player::doOnTick() {
    return;
}

pair<Line, string> Player::doUpdateStatus() {
    string healthMessage = "Health: " + std::to_string(getHealth());
    return pair<Line, string>{Line::L1, healthMessage};
}
