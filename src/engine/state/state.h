#ifndef STATE_H
#define STATE_H

#include "../entity/entity.h"
#include "../physics/physics.h"
#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include <list>
#include <map>
#include <memory>
#include <vector>
#include "../util/action.h"

using std::list;
using std::map;
using std::pair;
using std::unique_ptr;
using std::vector;

class State {
    map<int, list<unique_ptr<Entity>>> entities;
    unique_ptr<Physics> phys;
    virtual void doCreate() = 0;
    virtual void doOnTick() = 0;

public:
    State(unique_ptr<Physics> p);
    virtual ~State() = default;
    void create();
    void onTick();
    void addEntity(int height, unique_ptr<Entity> e);
    void addEntities(int height, list<unique_ptr<Entity>> &ents);
    bool checkCollisions(Entity *e, list<Entity*> others);
    void updateActions(const vector<Action> &inputs);
    vector<pair<const Posn &, const Bitmap &>> drawList();
};

#endif