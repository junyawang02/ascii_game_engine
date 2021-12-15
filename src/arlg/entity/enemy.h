#ifndef ENEMY_H
#define ENEMY_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/collider.h"
#include "damageable.h"
#include <memory>

using std::unique_ptr;

class Enemy: public Acceptor<Damageable, Enemy, Collider> {
public:
    Enemy(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> mvt, float health);
    Enemy(int x, int y, unique_ptr<Sprite> s, float health);
    Enemy(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> mvt, unique_ptr<Collider> c, float health);
    Enemy(int x, int y, unique_ptr<Sprite> s, unique_ptr<Collider> c, float health);
    bool isEnemy() override;
};

#endif
