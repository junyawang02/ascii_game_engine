#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "../../engine/entity/entity.h"
#include "../../engine/movement/movement.h"
#include "../../engine/sprite/sprite.h"
#include "../../config/colDecider.h"
#include <memory>

using std::unique_ptr;

class Damageable : public Entity {
    int health;

public:
    Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<Movement> m,
               unique_ptr<Collider> c, int health);
    void addHealth(int n);
    int getHealth();
};

#endif
