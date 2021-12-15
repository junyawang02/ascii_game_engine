#include "enemy.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/sprite/sprite.h"
#include "../../engine/util/acceptor.h"
#include "../collider/enemyCollider.h"
#include <memory>

using std::make_unique;

Enemy::Enemy(int x, int y, unique_ptr<Sprite> s, unique_ptr<MovementComponent> mvt, float health) : Acceptor{x, y, std::move(s), std::move(mvt), make_unique<EnemyCollider>(this), health} {}

Enemy::Enemy(int x, int y, unique_ptr<Sprite> s, float health) : Acceptor{x, y, std::move(s), make_unique<EnemyCollider>(this), health} {}

bool Enemy::isEnemy() { return true; }
