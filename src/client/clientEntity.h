#ifndef CLIENT_ENTITY_H
#define CLIENT_ENTITY_H

#include "../sprite/sprite.h"
#include "../util/posn.h"
#include "../entity/entity.h"
#include <memory>

using std::unique_ptr;

class ClientEntity : public Entity {
    void doCreate() override;
    void doOnTick() override;

public:
    ClientEntity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Movement> m);
};

#endif