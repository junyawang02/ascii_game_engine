#include "sprite.h"
#include "bitmap.h"

const Bitmap &Sprite::getFrame() const { return doGetFrame(); }

const Bitmap &Sprite::nextFrame() { return doNextFrame(); }
