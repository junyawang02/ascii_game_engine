#ifndef CONTROL_H
#define CONTROL_H

#include "../util/action.h"
#include "../util/posn.h"
#include "movementComponent.h"
#include <map>
#include <vector>

using std::map;
using std::vector;

class Entity;

class Control : public MovementComponent {
    vector<size_t> controlNums;
    map<Action, Posn> moves;
    Posn velocity(const Entity &e) override;

public:
    Control(vector<size_t> con, map<Action, Posn> m);
    Control(vector<size_t> con);
    Control(size_t con, map<Action, Posn> m);
    Control(size_t con);
};

#endif
