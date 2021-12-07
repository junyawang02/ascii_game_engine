#ifndef PHYSICS_H
#define PHYSICS_H

#include "../entity/entity.h"
#include "border.h"
#include <map>
#include <memory>
#include <list>

using std::map;
using std::unique_ptr;
using std::list;

class Physics {
    unique_ptr<Border> bor;

public:
    Physics(bool solid);
    Physics(unique_ptr<Border> b);
    void solidBorder(bool solid);
    void setBorder(unique_ptr<Border> b);
    void stepHelp(Entity *ent, Posn vel, list<Entity *> &others);
    void step(list<Entity *> &entities);
};

#endif
