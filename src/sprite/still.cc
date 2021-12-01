#include "still.h"
#include "bitmap.h"

Still::Still(Bitmap b) : bmap{b} {}

const Bitmap &Still::doGetFrame() {
    return bmap;
}

const Bitmap &Still::doNextFrame() {
    return bmap;
}
