#ifndef POPUP_COLLIDER
#define POPUP_COLLIDER

#include "../../config/collider.h"

class Popup;

class PopupCollider : public Collider {
    Popup *popup;
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;
    void doVisit(Health *e) override;

public:
    PopupCollider(Popup *p);
};

#endif
