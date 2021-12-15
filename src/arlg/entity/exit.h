#ifndef EXIT_H
#define EXIT_H

#include "arlgEntity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/collider.h"

class Exit: public Acceptor<ARLGEntity, Exit, Collider> {
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
