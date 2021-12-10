#include "level.h"

#include "../../engine/physics/physics.h"
#include "../../engine/state/state.h"
#include "../../engine/entity/entity.h"
#include "../entity/player.h"
#include "../../engine/util/myRandom.h"
#include "../entity/damageable.h"
#include <memory>

using std::make_unique;
using std::unique_ptr;

Level::Level(): State{make_unique<Physics>(true)} {}

void Level::doCreate() {
    int numEnemies = myRandom(5, 10);
    list<unique_ptr<Entity>> ents;
    list<Entity*> entPtrs;

    unique_ptr<Player> p = make_unique<Player>(myRandom(1, 78), myRandom(1, 20), 0);
    entPtrs.push_back(p.get());
    ents.emplace_back(std::move(p));

    for (int i = 0 ; i < numEnemies ; ++i) {
        int x = myRandom(1, 78);
        int y = myRandom(1, 20);
        unique_ptr<Damageable> e = getEnemy(x, y);
        while (checkCollisions(e.get(), entPtrs)) {
            x = myRandom(1, 78);
            y = myRandom(1, 20);
            e->setPos(x, y);
        }
        entPtrs.push_back(e.get());
        ents.emplace_back(std::move(e));
    }
    addEntities(0, ents);
}

void Level::doOnTick() {
    return;
}

unique_ptr<Damageable> Level::getEnemy(int x, int y) { return doGetEnemy(x, y); }
