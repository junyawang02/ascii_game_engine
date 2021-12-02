#ifndef INERT_H
#define INERT_H

#include "movement.h"
#include "../util/posn.h"

class Inert : public Movement {
    Posn velocity() override;
};

#endif
