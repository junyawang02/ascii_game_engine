#include "viewBorder.h"
#include "../entity/entity.h"
#include "../util/posn.h"

void ViewBorder::doBorderStep(Entity *e) {
    Posn pos = e->getPos();
    if (pos.x < 1 || pos.x > 78 || pos.y < 1 || pos.y > 20) {
        e->decrementCount();
    } else {
        e->resetCount();
    }
}
