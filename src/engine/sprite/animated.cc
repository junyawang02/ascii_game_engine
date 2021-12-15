#include "animated.h"
#include <vector>
#include "bitmap.h"
#include "sprite.h"

using std::vector;

Animated::Animated(vector<Bitmap> b): bmaps{b}, curFrame{0} {}

const Bitmap &Animated::doGetFrame() const {
    return bmaps[curFrame];
}

const Bitmap &Animated::doNextFrame() {
    if (curFrame == bmaps.size() - 1) {
        curFrame = 0;
    } else {
        ++curFrame;
    }
    return bmaps[curFrame];
}
