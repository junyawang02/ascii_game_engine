#ifndef BULLET_H
#define BULLET_H

#include "../../config/collider.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/border.h"
#include "../../engine/util/posn.h"
#include "arlgEntity.h"

class Bullet : public Acceptor<ARLGEntity, Bullet, Collider> {
    bool enemy;
    int iframes;
    void doBorderCollide(Border b) override;
    void doOnTick() override;

public:
    Bullet(Posn p, int x, int y, char c, bool iframe);
    bool invincible();
    bool isFromEnemy();
};

#endif
