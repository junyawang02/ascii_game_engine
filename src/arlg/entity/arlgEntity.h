#ifndef ARLGENTITY_H
#define ARLGENTITY_H

#include "../../config/collider.h"
#include "../../engine/entity/entity.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/sprite/sprite.h"
#include <memory>

using std::unique_ptr;

class ARLGEntity : public Entity {
public:
    ARLGEntity(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> m,
               unique_ptr<Collider> c);
    ARLGEntity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c);
    virtual bool isEnemy();
};

#endif
