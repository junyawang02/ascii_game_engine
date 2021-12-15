#include "tail.h"
#include "../movement/attached.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../collider/tailCollider.h"
#include <memory>

using std::make_unique;

Tail::Tail(int x, int y, Entity *lead) : Acceptor{x, y, make_unique<Still>(Bitmap{'s'}),
                                                  make_unique<Attached>(lead),
                                                  make_unique<TailCollider>(this)} {}
