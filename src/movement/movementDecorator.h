#ifndef MOVEMENTDECORATOR_H
#define MOVEMENTDECORATOR_H

#include "movement.h"
#include "../util/posn.h"
#include <memory>

using std::unique_ptr;

class Entity;

class MovementDecorator : public Movement {
protected:
    unique_ptr<Movement> component;
public:
    MovementDecorator(unique_ptr<Movement> c);
    virtual ~MovementDecorator() = default;
};

#endif
