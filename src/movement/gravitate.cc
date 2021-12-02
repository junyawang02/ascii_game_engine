#include "gravitate.h"
#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

Gravitate::Gravitate(Side s, int sp, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, side{s}, speed{sp} {}

Posn Gravitate::velocity() {
    Posn vel{0, 0};
    switch (side) {
    case UP: {
        vel.y = -speed;
        break;
    }
    case DOWN: {
        vel.y = speed;
        break;
    }
    case RIGHT: {
        vel.x = speed;
        break;
    }
    case LEFT: {
        vel.x = -speed;
        break;
    }
    default: {
        break; // should not be reached
    }
    }
    return vel + component->getVelocity();
}
