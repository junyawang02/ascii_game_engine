#include "exitCollider.h"
#include "../entity/exit.h"
#include "../../config/colDecider.h"

ExitCollider::ExitCollider(Exit *e): Collider{e}, exit{e} {}

void ExitCollider::doVisit(Player &e) {
    exit->finish();
}
