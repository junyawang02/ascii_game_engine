#ifndef HEALTH_H
#define HEALTH_H

#include "arlgEntity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/colDecider.h"

class Health: public Acceptor<ARLGEntity, Health, Collider> { 
public:
    Health(int x, int y);
};

#endif
