#include "bullet.h"
#include "../../engine/movement/linear.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/still.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/posn.h"
#include "../collider/bulletCollider.h"
#include "../../engine/util/border.h"
#include <memory>

using std::make_unique;

Bullet::Bullet(Posn p, int x, int y, char c) : Acceptor{p.x + x/2, p.y + y/2, make_unique<Still>(Bitmap{c}),
                                                        make_unique<Linear>(x, y),
                                                        make_unique<BulletCollider>(this)} {}


void Bullet::doBorderCollide(Border b) { flagDestroy(); }
