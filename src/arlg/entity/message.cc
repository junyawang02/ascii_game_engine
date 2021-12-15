#include "message.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/action.h"
#include "sprites.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::pair;
using std::vector;

Message::Message(bool win) : Acceptor{4, 1, make_unique<Still>(Bitmap{win ? SPRITES::win : SPRITES::loss}),
                                      make_unique<Collider>(this)},
                             delay{3} {}

pair<bool, bool> Message::doEndState() {
    --delay;
    if (delay <= 0) {
        const vector<Action> &acts = getActions();
        for (const auto &act : acts) {
            if (act != Action::NONE)
                return pair<bool, bool>{true, true};
        }
    }
    return pair<bool, bool>{false, false};
}
