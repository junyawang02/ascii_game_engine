#include "movement.h"
#include "../util/posn.h"

Posn Movement::getVelocity(const Posn &pos) { return velocity(pos); }
