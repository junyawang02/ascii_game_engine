#include "loss.h"
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

Loss::Loss() : State{make_unique<Physics>(false)} {}

void Loss::doCreate(Game &g) {
    const string end{"Press any key to exit."};
    g.updateViews(Line::L1, end);
    addEntity(0, make_unique<Message>(false));
}
