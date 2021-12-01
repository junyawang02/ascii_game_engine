#include "clientEntity.h"
#include "memory.h"

ClientEntity::ClientEntity(int x, int y, unique_ptr<Sprite> s) : Entity{x, y, std::move(s)} {}

void ClientEntity::doCreate() { return; }

void ClientEntity::doOnTick() { return; }
