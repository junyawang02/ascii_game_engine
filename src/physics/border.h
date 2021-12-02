#ifndef BORDER_H
#define BORDER_H

class Entity;

class Border {
    virtual void doBorderStep(Entity *e) = 0;
public:
    virtual ~Border() = default;
    void borderStep(Entity *e);
};

#endif
