#ifndef HEAD_COLLIDER
#define HEAD_COLLIDER

#include "../../config/colDecider.h"

class HeadCollider: public Collider {
    Head *h;
public:
    HeadCollider(Head *h);
};

#endif