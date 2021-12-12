#include "win.h"
#include "../../engine/entity/entity.h"
#include "../../engine/model/game.h"
#include "../../engine/physics/physics.h"
#include "../../engine/state/state.h"
#include "../../engine/util/line.h"
#include "../../engine/util/action.h"
#include "../entity/message.h"
#include <memory>
#include <string>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

Win::Win() : State{make_unique<Physics>(false)} {}

void Win::doCreate(Game &g) {
    const string end{"Press any key to exit."};
    const string myName{"Made by Junya Wang"};
    const string partnerName{"Thanks to my partner, Jerry Wu!"};
    g.updateViews(Line::L1, myName);
    g.updateViews(Line::L2, partnerName);
    g.updateViews(Line::L3, end);
    addEntity(0, make_unique<Message>(true));
}
