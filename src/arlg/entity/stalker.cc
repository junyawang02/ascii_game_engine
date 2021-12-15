#include "stalker.h"
#include "../../engine/movement/follow.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "player.h"
#include <memory>

using std::make_unique;

Stalker::Stalker(int x, int y, Player *p) : Enemy{x, y, make_unique<Still>(Bitmap{2, 2, 'b'}), make_unique<Follow>(p, 1), 2} {}
