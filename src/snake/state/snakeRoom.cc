#include "snakeRoom.h"
#include "../../engine/entity/entity.h"
#include "../../engine/model/game.h"
#include "../../engine/physics/physics.h"
#include "../../engine/state/state.h"
#include "../../engine/util/line.h"
#include "../../engine/util/myRandom.h"
#include "../../engine/util/posn.h"
#include "../entity/head.h"
#include "../entity/fruit.h"
#include <list>
#include <memory>
#include <string>

using std::list;
using std::make_unique;
using std::unique_ptr;

SnakeRoom::SnakeRoom() : State{make_unique<Physics>(false)}, score{0} {}

void SnakeRoom::doCreate(Game &g) {
    string scoreMessage = "Score: " + std::to_string(score);
    g.updateViews(Line::L1, scoreMessage);
    
    list<unique_ptr<Entity>> ents;
    list<Entity *> entPtrs;

    // make head
    unique_ptr<Head> player = make_unique<Head>(39, 9);
    head = player.get();
    entPtrs.push_back(head);
    ents.emplace_back(std::move(player));

    // spawn fruits
    for (int i = 0; i < 5; ++i) {
        int x = myRandom(1, 78);
        int y = myRandom(1, 20);
        unique_ptr<Entity> e = make_unique<Fruit>(x, y);
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

void SnakeRoom::doOnTick(Game &g) {
    if (myRandom(1, 4) == 3) {
        unique_ptr<Entity> e = make_unique<Fruit>(myRandom(1, 78), myRandom(1, 20));
        addEntity(0, std::move(e));
    }
}
