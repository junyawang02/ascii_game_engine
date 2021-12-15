#ifndef BULLET_H
#define BULLET_H

#include "arlgEntity.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/posn.h"
#include "../../config/colDecider.h"
#include "../../engine/util/border.h"

class Bullet: public Acceptor<ARLGEntity, Bullet, Collider> {
    int iframes;
    void doBorderCollide(Border b) override;
    void doOnTick() override;
public:
    Bullet(Posn p, int x, int y, char c, bool iframe);
    bool invincible();
};

#endif
