#include "fruit.h"
#include "../../engine/movement/linear.h"
#include "../../engine/movement/control.h"
#include "../../engine/movement/gravitate.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/sprite/animated.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/myRandom.h"
#include "../../engine/util/border.h"
#include "../collider/fruitCollider.h"
#include <vector>
#include <memory>

using std::make_unique;
using std::vector;

Fruit::Fruit(int x, int y) : Acceptor{x, y, make_unique<Animated>(vector<Bitmap>{Bitmap{'o'}, Bitmap{'O'}, Bitmap{2, 2, 'o'}}),
                                    make_unique<FruitCollider>(this)} {}

void Fruit::doCreate() {
    int move = myRandom(0, 2);
    for (int i = 0 ; i < move ; ++i) {
        int first = myRandom(1, 3);
        if (first == 1)
            addMovement("linear", make_unique<Linear>(myRandom(0, 2), myRandom(0, 2)));
        else if (first == 2)
            addMovement("control", make_unique<Control>(0));
        else {
            int dir = myRandom(1, 4);
            Border b;
            if (dir == 1)
                b = Border::U;
            else if (dir == 2)
                b = Border::D;
            else if (dir == 3)
                b = Border::L;
            else
                b = Border::R;
            addMovement("gravitate", make_unique<Gravitate>(b, 1));
        }
    }
}

void Fruit::doOnTick() {
    if (myRandom(0, 3) == 2)
        nextForm();
}
