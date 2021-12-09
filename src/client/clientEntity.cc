#include "clientEntity.h"
#include "clientEntityCollider.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

ClientEntity::ClientEntity(int x, int y, unique_ptr<Sprite> s, unique_ptr<Movement> m) : Acceptor{x, y, std::move(s), std::move(m), make_unique<ClientEntityCollider>()} {}

void ClientEntity::doCreate() { return; }

void ClientEntity::doOnTick() { nextForm(); }
