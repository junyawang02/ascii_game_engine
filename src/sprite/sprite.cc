#include "sprite.h"
#include "bitmap.h"

const Bitmap &Sprite::getFrame() { return doGetFrame(); }

const Bitmap &Sprite::nextFrame() { return doNextFrame(); }
