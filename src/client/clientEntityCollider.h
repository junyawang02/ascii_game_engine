#ifndef CLIENT_ENTITY_COLLIDER
#define CLIENT_ENTTIY_COLLIDER

#include "collider.h"

class ClientEntityCollider: public Collider {
    void visit(ClientEntity &e) override;
};

#endif
