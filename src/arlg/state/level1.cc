#include "level1.h"
#include "level.h"
#include "../entity/damageable.h"
#include "../entity/walker.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

unique_ptr<Damageable> Level1::doGetEnemy(int x, int y) {
    return make_unique<Walker>(x, y);
}
