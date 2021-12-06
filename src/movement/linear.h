#ifndef LINEAR_H
#define LINEAR_H

#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <memory>

using std::unique_ptr;

class Entity;

class Linear : public MovementDecorator {
    Posn vel;
    Posn velocity(const Entity &e) override;

public:
    Linear(int x, int y, unique_ptr<Movement> c);
};

#endif
