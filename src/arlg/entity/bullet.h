#ifndef BULLET_H
#define BULLET_H

#include "arlgEntity.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/posn.h"
#include "../../config/colDecider.h"
#include "../../engine/util/border.h"

class Bullet: public Acceptor<ARLGEntity, Bullet, Collider> {
    void doBorderCollide(Border b) override;
public:
    Bullet(Posn p, int x, int y, char c);
};

#endif
