#include "movementDecorator.h"
#include "../util/posn.h"
#include "movement.h"
#include <memory>

using std::unique_ptr;

MovementDecorator::MovementDecorator(unique_ptr<Movement> c) : component {std::move(c)} {}
