#ifndef PHYSICS_H
#define PHYSICS_H

#include "../entity/entity.h"
#include <map>
#include <memory>
#include <list>

using std::map;
using std::list;

class Physics {
    bool solid;

public:
    Physics(bool s);
    void solidBorder(bool s);
    bool checkCollisionHelp(Entity *ent, Entity *other);
    bool checkCollision(Entity *ent, Entity *other);
    void stepHelp(Entity *ent, list<Entity *> &others);
    void step(list<Entity *> &entities);
    Border boundsCheck(Entity *e);
    void outOfBounds(Entity *e);
    void borderCollision(Entity *e);
};

#endif
