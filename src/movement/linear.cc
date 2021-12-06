#include "linear.h"
#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

using std::unique_ptr;

class Entity;

Linear::Linear(int x, int y, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, vel{Posn{x, y}} {}

Posn Linear::velocity(const Entity &e) { return vel + component->getVelocity(e); }