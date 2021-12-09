#include "clientEntityCollider.h"
#include "clientEntity.h"

void ClientEntityCollider::visit(ClientEntity &e) { e.flagDestroy(); }
