#include "player.h"
#include "../../engine/movement/control.h"
#include "../../engine/movement/inert.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../collider/playerCollider.h"
#include <memory>

using std::make_unique;

Player::Player(int x, int y, size_t c) : 
    Acceptor {x, y, make_unique<Still>(Bitmap{'p'}), 
                    make_unique<Control>(control, make_unique<Inert>()),
                    make_unique<PlayerCollider>(this), 5}, 
    control{c} {}

void Player::doCreate() {
    return;
}

void Player::doOnTick() {
    return;
}
