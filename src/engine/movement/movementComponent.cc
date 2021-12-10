#include "movementComponent.h"
#include "../util/posn.h"

class Entity;

Posn MovementComponent::getVelocity(const Entity &e) { return velocity(e); }
