#ifndef SPRITE_H
#define SPRITE_H

#include <memory>
#include <vector>

class Bitmap;

class Sprite {
    virtual const Bitmap &doGetFrame() const = 0;
    virtual const Bitmap &doNextFrame() = 0;
public:
    virtual ~Sprite() = default;
    const Bitmap &getFrame() const;
    const Bitmap &nextFrame();
};

#endif
