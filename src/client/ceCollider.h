#ifndef CLIENT_ENTITYC_H
#define CLIENT_ENTITYC_H

#include "clientEntity.h"

class ClientEntityCollider : public Visitor<ClientEntity> {
    void collide(ClientEntity &other) { other.flagDestroy(); }
};

#endif
