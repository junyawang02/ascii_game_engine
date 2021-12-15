#include "damageable.h"
#include "../../engine/entity/entity.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/sprite/sprite.h"
#include "arlgEntity.h"
#include <memory>

using std::unique_ptr;

Damageable::Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m, unique_ptr<Collider> c, float health) : ARLGEntity{x, y, std::move(s), std::move(m), std::move(c)}, health{health} {}

Damageable::Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c, float health) : ARLGEntity{x, y, std::move(s), std::move(c)}, health{health} {}

void Damageable::addHealth(float n) {
    health += n;
    if (health < 1)
        flagDestroy();
}

int Damageable::getHealth() { return health; }
