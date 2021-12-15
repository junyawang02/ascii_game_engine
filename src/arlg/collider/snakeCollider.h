#ifndef SNAKE_COLLIDER
#define SNAKE_COLLIDER

#include "../../config/colDecider.h"

class Snake;

class SnakeCollider: public Collider {
    Snake *snake;
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;
    void doVisit(Health *e) override;
public:
    SnakeCollider(Snake *s);
};

#endif
