#include "linear.h"
#include "../util/posn.h"
#include "movementComponent.h"

class Entity;

Linear::Linear(int x, int y) : MovementComponent{}, vel{Posn{x, y}} {}

Posn Linear::velocity(const Entity &e) { return vel; }
