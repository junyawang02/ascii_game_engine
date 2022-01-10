#include "snakeCollider.h"
#include "../entity/boss.h"
#include "../entity/bullet.h"
#include "../entity/enemy.h"
#include "../entity/health.h"
#include "../entity/player.h"
#include "../entity/snake.h"

SnakeCollider::SnakeCollider(Snake *s) : Collider{s}, snake{s} {}

void SnakeCollider::doVisit(Player *e) {
    bounce(e);
    e->addHealth(-1);
}

void SnakeCollider::doVisit(Enemy *e) {
    Boss *boss = dynamic_cast<Boss *>(e);
    if (boss)
        return;
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
