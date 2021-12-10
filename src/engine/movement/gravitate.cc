#include "gravitate.h"
#include "../entity/entity.h"
#include "../util/border.h"
#include "../util/posn.h"
#include "movementComponent.h"

Gravitate::Gravitate(Border s, int sp) : MovementComponent{}, side{s}, speed{sp} {}

Posn Gravitate::velocity(const Entity &e) {
    Posn pos = e.getPos();
    Posn vel = Posn{0, 0};
    switch (side) {
    case Border::U: {
        if (pos.y - speed >= 1)
            vel.y = -speed;
        else if (pos.y + speed <= 1)
            vel.y = speed;
        else
            vel.y = 1 - pos.y;
        break;
    }
    case Border::D: {
        if (pos.y + speed <= 20)
            vel.y = speed;
        else if (pos.y + speed >= 20)
            vel.y = -speed;
        else
            vel.y = 20 - pos.y;
        break;
    }
    case Border::R: {
        if (pos.x + speed <= 78)
            vel.x = speed;
        else if (pos.x + speed >= 78)
            vel.x = -speed;
        else
            vel.x = 78 - pos.x;
        break;
    }
    case Border::L: {
        if (pos.x + speed >= 1)
            vel.x = -speed;
        else if (pos.x + speed <= 1)
            vel.x = speed;
        else
            vel.x = 1 - pos.x;
        break;
    }
    default: {
        break; // should not be reached
    }
    }
    return vel;
}
