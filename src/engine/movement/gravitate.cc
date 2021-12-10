#include "gravitate.h"
#include "../entity/entity.h"
#include "../util/posn.h"
#include "../util/border.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

Gravitate::Gravitate(Border s, int sp, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, side{s}, speed{sp} {}

Posn Gravitate::velocity(const Entity &e) {
    Posn pos = e.getPos();
    Posn nextPos = pos + component->getVelocity(e);
    Posn vel = Posn{0, 0};
    switch (side) {
    case Border::U: {
        if (nextPos.y - speed >= 1)
            vel.y = -speed;
        else if (nextPos.y + speed <= 1)
            vel.y = speed;
        else
            vel.y = 1 - nextPos.y;
        break;
    }
    case Border::D: {
        if (nextPos.y + speed <= 20)
            vel.y = speed;
        else if (nextPos.y + speed >= 20)
            vel.y = -speed;
        else
            vel.y = 20 - nextPos.y;
        break;
    }
    case Border::R: {
        if (nextPos.x + speed <= 78)
            vel.x = speed;
        else if (nextPos.x + speed >= 78)
            vel.x = -speed;
        else
            vel.x = 78 - nextPos.x;
        break;
    }
    case Border::L: {
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
    return vel + component->getVelocity(e);
}
