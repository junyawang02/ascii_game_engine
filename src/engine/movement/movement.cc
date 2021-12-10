#include "movement.h"
#include "../util/posn.h"

class Entity;

Posn Movement::getVelocity(const Entity &e) { return velocity(e); }
