#ifndef CONTROL_H
#define CONTROL_H

#include "../util/action.h"
#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <map>
#include <memory>
#include <vector>

using std::map;
using std::unique_ptr;
using std::vector;

class Entity;

class Control : public MovementDecorator {
    vector<size_t> controlNums;
    map<Action, Posn> moves;
    Posn velocity(const Entity &e) override;

public:
    Control(vector<size_t> con, map<Action, Posn> m, unique_ptr<Movement> c);
    Control(vector<size_t> con, unique_ptr<Movement> c);
    Control(size_t con, map<Action, Posn> m, unique_ptr<Movement> c);
    Control(size_t con, unique_ptr<Movement> c);
};

#endif
