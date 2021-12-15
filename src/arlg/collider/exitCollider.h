#ifndef EXIT_COLLIDER
#define EXIT_COLLIDER

#include "arlgCollider.h"

class Exit;

class ExitCollider: public ARLGCollider {
    Exit *exit;
    void doVisit(Player *e) override;
public:
    ExitCollider(Exit *e);
};

#endif
