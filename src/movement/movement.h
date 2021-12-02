#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../util/posn.h"

class Movement {
    virtual Posn velocity(const Posn &pos) = 0;
public:
    virtual ~Movement() = default;
    Posn getVelocity(const Posn &pos);
};

#endif
