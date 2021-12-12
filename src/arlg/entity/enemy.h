#ifndef ENEMY_H
#define ENEMY_H

#include "../../engine/entity/entity.h"
#include "../../engine/util/acceptor.h"
#include "../../config/colDecider.h"
#include "damageable.h"

class Enemy: public Acceptor<Damageable, Enemy, Collider> {
public:
    Enemy(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> mvt, int health);
    Enemy(int x, int y, unique_ptr<Sprite> s, int health);
    bool isEnemy() override;
};

#endif
