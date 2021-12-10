#include "damageable.h"
#include "../../engine/entity/entity.h"
#include "../../engine/sprite/sprite.h"
#include "../../engine/movement/movementComponent.h"
#include <memory>

using std::unique_ptr;
using std::move;

Damageable::Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m, unique_ptr<Collider> c, int h): Entity{x, y, move(s), move(m), move(c)}, health{h} {}

Damageable::Damageable(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c, int h): Entity{x, y, move(s), move(c)}, health{h} {}

void Damageable::addHealth(int n) {
    health += n;
    if (health < 1) flagDestroy();
}

int Damageable::getHealth() { return health; }
