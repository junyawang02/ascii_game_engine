#include "damageable.h"
#include "../../engine/entity/entity.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/sprite/sprite.h"
#include "arlgEntity.h"
#include <memory>

using std::unique_ptr;

Damageable::Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m, unique_ptr<Collider> c, int h) : ARLGEntity{x, y, std::move(s), std::move(m), std::move(c)}, health{h} {}

Damageable::Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c, int h) : ARLGEntity{x, y, std::move(s), std::move(c)}, health{h} {}

void Damageable::addHealth(int n) {
    health += n;
    if (health < 1)
        flagDestroy();
}

int Damageable::getHealth() { return health; }
