#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../util/posn.h"

class Movement {
    virtual Posn velocity() = 0;
public:
    virtual ~Movement() = default;
    Posn getVelocity();
};

#endif
