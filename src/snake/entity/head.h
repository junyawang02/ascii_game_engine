#ifndef HEAD_H
#define HEAD_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/collider.h"
#include <vector>

using std::vector;

class Tail;

class Head : public Acceptor<Entity, Head, Collider> {
    vector<Tail*> tail;
    bool toGrow;
    bool dead;
    int count;
    void doOnTick() override;
    pair<bool, bool> doEndState() override;
public:
    Head(int x, int y);
    void setGrow(bool g);
    bool getGrow();
    void startCount();
    vector<Tail*> &getTail();
    void addTail(Tail *t);
};

#endif