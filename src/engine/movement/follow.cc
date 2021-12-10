#include "../util/posn.h"
#include "../entity/entity.h"
#include "movementComponent.h"
#include "follow.h"
#include <cmath>

Follow::Follow(Entity *ent, int s): MovementComponent{}, leader{ent}, speed{s} {}

Posn Follow::velocity(const Entity &e) {
    Posn pos = e.getPos();
    Posn lPos = leader->getPos();
    int xTiles = (speed % 2 == 0)? speed / 2 : speed / 2 + 1; // alloted tiles to move in x direction
    int yTiles = speed / 2;
    int extraX = 0;

    // calculate tiles needed to move towards leader
    if (abs(lPos.x - pos.x) < xTiles) {
        int temp = lPos.x - pos.x;
        yTiles += xTiles - abs(temp); // pass off extras
        xTiles = temp;
    } else if (pos.x > lPos.x) {
        xTiles *= -1;
    }
    if (abs(lPos.y - pos.y) < yTiles) {
        int temp = lPos.y - pos.y;
        extraX = yTiles - abs(temp);
        yTiles = temp;
    } else if (pos.y > lPos.y) {
        yTiles *= -1;
    }
    if (extraX > 0) {
        if (abs(lPos.x - (pos.x + xTiles)) < extraX) {
            extraX = lPos.x - (pos.x + xTiles);
            xTiles += extraX;
        } else if (pos.x + xTiles > lPos.x) {
            xTiles -= extraX;
        } else {
            xTiles += extraX;
        }
    }
    return Posn{xTiles, yTiles};
}
