#include "headCollider.h"
#include "../entity/head.h"

HeadCollider::HeadCollider(Head *h): Collider{h}, head{h} {}
