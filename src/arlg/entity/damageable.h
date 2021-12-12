#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "arlgEntity.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/sprite/sprite.h"
#include "../../config/colDecider.h"
#include <memory>

using std::unique_ptr;

class Damageable : public ARLGEntity {
    int health;

public:
    Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m,
               unique_ptr<Collider> c, int health);
    Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c, int health);
    virtual ~Damageable() = default;
    void addHealth(int n);
    int getHealth();
};

#endif
