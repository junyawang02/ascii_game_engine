#include "exitCollider.h"
#include "../entity/exit.h"

ExitCollider::ExitCollider(Exit *e): Collider{e}, exit{e} {}

void ExitCollider::doVisit(Player *e) {
    exit->finish();
}
