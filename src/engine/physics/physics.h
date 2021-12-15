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
    bool checkCollisionHelp(Entity *ent, Entity *other);
    void stepHelp(Entity *ent, list<Entity *> &others);
    Border getBorder(Entity *e);
    void outOfBounds(Entity *e);
    void borderCollision(Entity *e);

public:
    Physics(bool s);
    void solidBorder(bool s);
    bool checkCollision(Entity *ent, Entity *other);
    void step(list<Entity *> &entities);
    void singleStep(Entity *e, list<Entity *> &entities);
    bool inBounds(Entity *e);
};

#endif
