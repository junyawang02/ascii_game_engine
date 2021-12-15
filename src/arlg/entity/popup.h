#ifndef POPUP_H
#define POPUP_H

#include "../../config/collider.h"
#include "../../engine/entity/entity.h"
#include "enemy.h"

class Popup : public Enemy {
    bool inv;
    int formChange;
    void doOnTick() override;
public:
    Popup(int x, int y);
    bool invincible();
};

#endif
