#include "clientState.h"
#include "../movement/inert.h"
#include "../physics/physics.h"
#include "../sprite/animated.h"
#include "../sprite/bitmap.h"
#include "../sprite/still.h"
#include "clientEntity.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;

ClientState::ClientState(unique_ptr<Physics> p) : State{std::move(p)} {}

void ClientState::doCreate() {
    addEntity(1, make_unique<ClientEntity>(-5, 20, make_unique<Still>(Bitmap{'c'}), make_unique<Inert>()));
    addEntity(3, make_unique<ClientEntity>(0, 0, make_unique<Still>(Bitmap{'m'}), make_unique<Inert>()));
    addEntity(0, make_unique<ClientEntity>(2, 5, make_unique<Still>(Bitmap{10, 5, 'w'}), make_unique<Inert>()));
    addEntity(1, make_unique<ClientEntity>(40, 10, make_unique<Still>(Bitmap{vector<Cell>{{0, 0, 'S'}, {0, 1, 's'}, {1, 1, 's'}, {2, 1, 's'}}}), make_unique<Inert>()));
    addEntity(2, make_unique<ClientEntity>(60, 10, make_unique<Animated>(vector<Bitmap>{Bitmap{'c'}, Bitmap{'C'}, Bitmap{5, 5, 'm'}}), make_unique<Inert>()));
}

void ClientState::doOnTick() { return; }
