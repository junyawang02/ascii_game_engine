#ifndef STATE_H
#define STATE_H

#include "../entity/entity.h"
#include "../sprite/bitmap.h"
#include "../util/posn.h"
#include <memory>
#include <vector>

using std::pair;
using std::unique_ptr;
using std::vector;

class State {
    vector<unique_ptr<Entity>> entities;
    virtual void doCreate() = 0;
    virtual void doOnTick() = 0;

public:
    virtual ~State() = default;
    void create();
    void onTick();
    void addEntity(unique_ptr<Entity> e);
    vector<pair<const Posn &, const Bitmap &>> drawList();
};

#endif