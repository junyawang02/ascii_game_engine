#include "clientEntityCollider.h"
#include "clientEntity.h"

void ClientEntityCollider::doVisit(ClientEntity &e) { e.flagDestroy(); }
