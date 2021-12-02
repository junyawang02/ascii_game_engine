#include "clientEntity.h"
#include <memory>

using std::unique_ptr;

ClientEntity::ClientEntity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Movement> m) : Entity{x, y, std::move(s), std::move(m)} {}

void ClientEntity::doCreate() { return; }

void ClientEntity::doOnTick() { nextForm(); }
