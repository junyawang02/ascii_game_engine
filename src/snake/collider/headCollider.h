#ifndef HEAD_COLLIDER
#define HEAD_COLLIDER

#include "../../config/colDecider.h"

class Head;

class HeadCollider: public Collider {
    Head *head;
public:
    HeadCollider(Head *h);
};

#endif