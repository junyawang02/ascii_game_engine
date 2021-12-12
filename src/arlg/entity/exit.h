#ifndef EXIT_H
#define EXIT_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/colDecider.h"

class Exit: public Acceptor<Entity, Exit, Collider> {
    bool isOpen;
    bool isFinish;
    pair<Line, string> doUpdateStatus() override;
    pair<bool, bool> doEndState() override;

public:
    Exit(int x, int y);
    void open();
    void finish();
};

#endif
