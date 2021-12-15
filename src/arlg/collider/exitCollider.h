#ifndef EXIT_COLLIDER
#define EXIT_COLLIDER

#include "../../config/collider.h"

class Exit;

class ExitCollider: public Collider {
    Exit *exit;
    void doVisit(Player *e) override;
public:
    ExitCollider(Exit *e);
};

#endif
