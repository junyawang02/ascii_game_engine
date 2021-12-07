#ifndef STILL_H
#define STILL_H

#include "bitmap.h"
#include "sprite.h"

class Still : public Sprite {
    Bitmap bmap;
    const Bitmap &doGetFrame() const override;
    const Bitmap &doNextFrame() override;

public:
    Still(Bitmap b);
};

#endif
