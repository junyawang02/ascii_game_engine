#ifndef SNAKE_H
#define SNAKE_H

#include "../../config/collider.h"
#include "../../engine/entity/entity.h"
#include "enemy.h"

class Snake : public Enemy {
    bool horizontal;
    void doBorderCollide(Border b) override;
    void doCreate() override;

public:
    Snake(int x, int y, bool horizontal);
};

#endif
