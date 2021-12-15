#ifndef HEAD_H
#define HEAD_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/colDecider.h"

class Head : public Acceptor<Entity, Head, Collider> {
    bool toGrow;
    int count;
    void doOnTick() override;
    pair<bool, bool> doEndState() override;
public:
    Head(int x, int y);
    void setGrow(bool g);
    bool getGrow();
    void startCount();
};

#endif