#include "clientEntityCollider.h"
#include "clientEntity.h"

ClientEntityCollider::ClientEntityCollider(ClientEntity *s): Collider{s} {}

void ClientEntityCollider::doVisit(ClientEntity &e) { 
    self->flagDestroy();
    e.flagDestroy(); 
}
