#ifndef HEALTH_H
#define HEALTH_H

#include "../../config/collider.h"
#include "../../engine/util/acceptor.h"
#include "arlgEntity.h"

class Health : public Acceptor<ARLGEntity, Health, Collider> {
public:
    Health(int x, int y);
};

#endif
