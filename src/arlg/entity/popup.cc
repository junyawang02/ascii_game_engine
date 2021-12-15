#include "popup.h"
#include "../../engine/sprite/animated.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/util/myRandom.h"
#include "bullet.h"
#include "enemy.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;

Popup::Popup(int x, int y) : Enemy{x, y, make_unique<Animated>(vector<Bitmap>{Bitmap{'c'}, Bitmap{'D'}}), 4},
                             inv{true}, formChange{myRandom(2, 4)} {}

void Popup::doOnTick() {
    --formChange;
    if (formChange <= 0) {
        if (inv) {
            nextForm();
            addSpawn(make_unique<Bullet>(getPos(), 0, -2, 'X', false));
            addSpawn(make_unique<Bullet>(getPos(), -2, 0, 'X', false));
            addSpawn(make_unique<Bullet>(getPos(), 0, 2, 'X', false));
            addSpawn(make_unique<Bullet>(getPos(), 2, 0, 'X', false));
            inv = false;
        } else {
            nextForm();
            inv = true;
        }
    }
    formChange = myRandom(2, 4);
}

bool Popup::invincible() { return inv; }
