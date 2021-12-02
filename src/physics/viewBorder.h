#ifndef VIEWBORDER_H
#define VIEWBORDER_H

#include "border.h"

class Entity;

class ViewBorder : public Border {
    void doBorderStep(Entity *e) override;
};

#endif
