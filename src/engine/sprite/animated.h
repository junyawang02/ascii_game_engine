#ifndef ANIMATED_H
#define ANIMATED_H

#include <vector>
#include "bitmap.h"
#include "sprite.h"

using std::vector;

class Animated: public Sprite {
    vector<Bitmap> bmaps;
    size_t curFrame;

    const Bitmap &doGetFrame() const override;
    const Bitmap &doNextFrame() override;

public:
    Animated(vector<Bitmap> b);
};

#endif
