#ifndef INERT_H
#define INERT_H

#include "movement.h"
#include "../util/posn.h"

class Entity;

class Inert : public Movement {
    Posn velocity(const Entity &e) override;
};

#endif
