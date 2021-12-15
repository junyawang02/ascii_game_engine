#include "snakeCollider.h"
#include "../entity/enemy.h"
#include "../entity/player.h"
#include "../entity/bullet.h"
#include "../entity/health.h"
#include "../entity/snake.h"

SnakeCollider::SnakeCollider(Snake *s) : Collider{s}, snake{s} {}

void SnakeCollider::doVisit(Player *e) {
    bounce(e);
    e->addHealth(-1);
}

void SnakeCollider::doVisit(Enemy *e) {
    bounce(e);
}

void SnakeCollider::doVisit(Bullet *e) {
    if (snake->getPos() != e->getPos())
        snake->addHealth(-1);
    destroyOther(e);
}

void SnakeCollider::doVisit(Health *e) {
    snake->addHealth(1);
    destroyOther(e);
}
