#ifndef SNAKE_COLLIDER
#define SNAKE_COLLIDER

#include "arlgCollider.h"

class Snake;

class SnakeCollider: public ARLGCollider {
    Snake *snake;
    void doVisit(Player *e) override;
    void doVisit(Enemy *e) override;
    void doVisit(Bullet *e) override;
    void doVisit(Health *e) override;
public:
    SnakeCollider(Snake *s);
};

#endif
