#include "arlgEntity.h"
#include "../../config/collider.h"
#include "../../engine/entity/entity.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/sprite/sprite.h"
#include <memory>

using std::unique_ptr;

ARLGEntity::ARLGEntity(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m,
           unique_ptr<Collider> c) : Entity{x, y, std::move(s), std::move(m), std::move(c)} {}

ARLGEntity::ARLGEntity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c) : Entity{x, y, std::move(s), std::move(c)} {}

bool ARLGEntity::isEnemy() { return false; }
