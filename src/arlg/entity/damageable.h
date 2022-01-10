#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "../../config/collider.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/sprite/sprite.h"
#include "arlgEntity.h"
#include <memory>

using std::unique_ptr;

class Damageable : public ARLGEntity {
    float health;

public:
    Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m,
               unique_ptr<Collider> c, float health);
    Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c, float health);
    virtual ~Damageable() = default;
    void addHealth(float n);
    int getHealth();
};

#endif
