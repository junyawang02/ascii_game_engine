#include "level.h"
#include "../../engine/entity/entity.h"
#include "../../engine/model/game.h"
#include "../../engine/physics/physics.h"
#include "../../engine/state/state.h"
#include "../../engine/util/line.h"
#include "../../engine/util/myRandom.h"
#include "../../engine/util/posn.h"
#include "../entity/arlgEntity.h"
#include "../entity/damageable.h"
#include "../entity/exit.h"
#include "../entity/fire.h"
#include "../entity/player.h"
#include <list>
#include <memory>
#include <string>

using std::list;
using std::make_unique;
using std::unique_ptr;

class Game;

Level::Level() : State{make_unique<Physics>(true)} {}

void Level::doCreate(Game &g) {
    string stage = "Level " + std::to_string(getNumber());
    g.updateViews(Line::L2, stage);
    string healthMessage = "Health: 5";
    g.updateViews(Line::L1, healthMessage);
    
    list<unique_ptr<Entity>> ents;
    list<Entity *> entPtrs;

    // make player
    Posn playerPos = Posn{myRandom(1, 78), myRandom(1, 20)};
    unique_ptr<Player> player = make_unique<Player>(playerPos.x, playerPos.y, 0);
    Player *playerp = player.get();
    entPtrs.push_back(playerp);
    ents.emplace_back(std::move(player));

    // make exit
    Posn exitPos = Posn{myRandom(1, 78), myRandom(1, 20)};
    while (exitPos == playerPos)
        exitPos = Posn{myRandom(1, 78), myRandom(1, 20)};
    unique_ptr<Exit> exit = make_unique<Exit>(exitPos.x, exitPos.y);
    entPtrs.push_back(exit.get());

    // generate enemies and fires
    int numEnemies = myRandom(5, 10);
    int numFires = myRandom(7, 12);
    for (int i = 0; i < numEnemies + numFires; ++i) {
        int x = myRandom(1, 78);
        int y = myRandom(1, 20);
        unique_ptr<Entity> e;
        if (i < numEnemies) {
            e = getEnemy(x, y, playerp);
        } else {
            e = make_unique<Fire>(x, y);
        }
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
        ARLGEntity *ent = static_cast<ARLGEntity *>(entity); // downcast
        if (ent->isEnemy())
            return;
    }
    list<Entity *> exitLevel = getEntities(-1);
    Posn exitPos = (*exitLevel.begin())->getPos();
    unique_ptr<Exit> exit = make_unique<Exit>(exitPos.x, exitPos.y);
    exit->open();
    addEntity(0, std::move(exit));
}

int Level::getNumber() { return doGetNumber(); }

unique_ptr<Enemy> Level::getEnemy(int x, int y, Player *p) { return doGetEnemy(x, y, p); }
