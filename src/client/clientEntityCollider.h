#ifndef CLIENT_ENTITY_COLLIDER
#define CLIENT_ENTTIY_COLLIDER

#include "collider.h"

class ClientEntityCollider: public Collider {
    void doVisit(ClientEntity &e) override;
public:
    ClientEntityCollider(ClientEntity *s);
};

#endif
