#include "level.h"
#include "../../engine/entity/entity.h"
#include "../../engine/physics/physics.h"
#include "../../engine/state/state.h"
#include "../../engine/util/myRandom.h"
#include "../../engine/util/posn.h"
#include "../entity/damageable.h"
#include "../entity/player.h"
#include "../entity/exit.h"
#include "../entity/arlgEntity.h"
#include <memory>
#include <list>

using std::make_unique;
using std::unique_ptr;
using std::list;

class Game;

Level::Level() : State{make_unique<Physics>(true)} {}

void Level::doCreate(Game &g) {
    list<unique_ptr<Entity>> ents;
    list<Entity *> entPtrs;

    Posn playerPos = Posn{myRandom(1, 78), myRandom(1, 20)};
    unique_ptr<Player> player = make_unique<Player>(playerPos.x, playerPos.y, 0);
    entPtrs.push_back(player.get());
    ents.emplace_back(std::move(player));

    Posn exitPos = Posn{myRandom(1, 78), myRandom(1, 20)};
    while (exitPos == playerPos)
        exitPos = Posn{myRandom(1, 78), myRandom(1, 20)};
    unique_ptr<Exit> exit = make_unique<Exit>(exitPos.x, exitPos.y);
    entPtrs.push_back(exit.get());

    int numEnemies = myRandom(0, 0);
    for (int i = 0; i < numEnemies; ++i) {
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
    addEntity(-1, std::move(exit));
    addEntities(0, ents);
}

void Level::doOnTick(Game &g) {
    list<Entity *> entityList = getEntities(0);
    for (auto &entity : entityList) {
        ARLGEntity* ent = static_cast<ARLGEntity *>(entity); // downcast
        if (ent->isEnemy())
            return;
    }
    list<Entity *> exitLevel = getEntities(-1);
    Posn exitPos = (*exitLevel.begin())->getPos();
    unique_ptr<Exit> exit = make_unique<Exit>(exitPos.x, exitPos.y);
    exit->open();
    addEntity(0, std::move(exit));
}

unique_ptr<Damageable> Level::getEnemy(int x, int y) { return doGetEnemy(x, y); }
