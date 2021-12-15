#include "health.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../collider/healthCollider.h"
#include <memory>

using std::make_unique;

Health::Health(int x, int y) : Acceptor{x, y, make_unique<Still>(Bitmap{'h'}), make_unique<HealthCollider>(this)} {}
