#ifndef HOLDCONTROL_H
#define HOLDCONTROL_H

#include "../../engine/util/action.h"
#include "../../engine/util/posn.h"
#include "../../engine/movement/movementComponent.h"
#include <map>
#include <vector>

using std::map;
using std::vector;

class Entity;

class HoldControl : public MovementComponent {
    size_t controlNum;
    map<Action, Posn> moves;
    Posn velocity(const Entity &e) override;
    Action current;

public:
    HoldControl(size_t con, map<Action, Posn> m);
    HoldControl(size_t con);
};

#endif
