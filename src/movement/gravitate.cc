#include "gravitate.h"
#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

Gravitate::Gravitate(Side s, int sp, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, side{s}, speed{sp} {}

Posn Gravitate::velocity(const Posn &pos) {
    Posn nextPos = pos + component->getVelocity(pos);
    Posn vel = Posn{0, 0};
    switch (side) {
    case UP: {
        if (nextPos.y - speed >= 1)
            vel.y = -speed;
        else if (nextPos.y + speed <= 1)
            vel.y = speed;
        else
            vel.y = 1 - nextPos.y;
        break;
    }
    case DOWN: {
        if (nextPos.y + speed <= 20)
            vel.y = speed;
        else if (nextPos.y + speed >= 20)
            vel.y = -speed;
        else
            vel.y = 20 - nextPos.y;
        break;
    }
    case RIGHT: {
        if (nextPos.x + speed <= 78)
            vel.x = speed;
        else if (nextPos.x + speed >= 78)
            vel.x = -speed;
        else
            vel.x = 78 - nextPos.x;
        break;
    }
    case LEFT: {
        if (nextPos.x + speed >= 1)
            vel.x = -speed;
        else if (nextPos.x + speed <= 1)
            vel.x = speed;
        else
            vel.x = 1 - nextPos.x;
        break;
    }
    default: {
        break; // should not be reached
    }
    }
    return vel + component->getVelocity(pos);
}
