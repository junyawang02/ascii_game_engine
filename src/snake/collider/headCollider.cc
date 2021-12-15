#include "../entity/head.h"
#include "headCollider.h"

HeadCollider::HeadCollider(Head *h): Collider{h}, head{h} {}
