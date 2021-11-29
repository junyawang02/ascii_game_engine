#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../util/action.h"

class Controller {
    virtual Action action() = 0;
public:
    virtual ~Controller() = default;
    Action getAction();
};

#endif