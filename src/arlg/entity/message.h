#ifndef MESSAGE_H
#define MESSAGE_H

#include "../../config/colDecider.h"
#include "../../engine/entity/entity.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/util/acceptor.h"
#include <vector>

using std::pair;
using std::vector;

class Message : public Acceptor<Entity, Message, Collider> {
    int delay;
    pair<bool, bool> doEndState() override;

public:
    Message(bool win);
};

#endif
