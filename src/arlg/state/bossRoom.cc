#include "bossRoom.h"
#include "../../engine/entity/entity.h"
#include "../../engine/model/game.h"
#include "../../engine/physics/physics.h"
#include "../../engine/state/state.h"
#include "../../engine/util/line.h"
#include "../../engine/util/myRandom.h"
#include "../../engine/util/posn.h"
#include "../entity/player.h"
#include "../entity/boss.h"
#include <list>
#include <memory>
#include <string>

using std::list;
using std::make_unique;
using std::unique_ptr;

BossRoom::BossRoom() : State{make_unique<Physics>(true)} {}

void BossRoom::doCreate(Game &g) {
    string stage = "Level 6";
    g.updateViews(Line::L2, stage);
    string healthMessage = "Health: 5";
    g.updateViews(Line::L1, healthMessage);

    list<unique_ptr<Entity>> ents;
    list<Entity *> entPtrs;

    // make player
    unique_ptr<Player> player = make_unique<Player>(39, 18, 0);
    Player *playerp = player.get();
    entPtrs.push_back(playerp);
    ents.emplace_back(std::move(player));

    // make boss
    unique_ptr<Boss> boss = make_unique<Boss>(39, 7, playerp);
    entPtrs.push_back(boss.get());
    ents.emplace_back(std::move(boss));

    addEntities(0, ents);
}
