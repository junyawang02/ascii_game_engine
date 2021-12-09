#include "clientState.h"
#include "../movement/control.h"
#include "../movement/follow.h"
#include "../movement/gravitate.h"
#include "../movement/inert.h"
#include "../movement/linear.h"
#include "../physics/physics.h"
#include "../sprite/animated.h"
#include "../sprite/bitmap.h"
#include "../sprite/still.h"
#include "../util/action.h"
#include "clientEntity.h"
#include <map>
#include <memory>
#include <vector>

using std::make_unique;
using std::map;
using std::vector;

ClientState::ClientState(unique_ptr<Physics> p) : State{std::move(p)} {}

void ClientState::doCreate() {
    unique_ptr<Entity> m = make_unique<ClientEntity>(1, 1, make_unique<Still>(Bitmap{'c'}), make_unique<Linear>(1, 1, make_unique<Inert>()));
    addEntity(0, make_unique<ClientEntity>(0, 0, make_unique<Still>(Bitmap{'m'}), make_unique<Linear>(6, 1, make_unique<Inert>())));
    unique_ptr<Entity> e = make_unique<ClientEntity>(30, 15, make_unique<Still>(Bitmap{3, 3, 'w'}), make_unique<Inert>());
    addEntity(0, make_unique<ClientEntity>(2, 5, make_unique<Still>(Bitmap{'g'}), make_unique<Follow>(m.get(), 4, make_unique<Inert>())));
    addEntity(0, std::move(e));
    addEntity(0, std::move(m));
    addEntity(0, make_unique<ClientEntity>(40, 10, make_unique<Still>(Bitmap{vector<Cell>{{0, 0, 'S'}, {0, 1, 's'}, {1, 1, 's'}, {2, 1, 's'}}}), make_unique<Inert>()));
    addEntity(0, make_unique<ClientEntity>(60, 10, make_unique<Animated>(vector<Bitmap>{Bitmap{'c'}, Bitmap{'C'}, Bitmap{5, 5, 'm'}}), make_unique<Gravitate>(U, 2, make_unique<Linear>(-1, -1, make_unique<Inert>()))));
    addEntity(0, make_unique<ClientEntity>(1, 15, make_unique<Still>(Bitmap{'p'}), make_unique<Control>(0, make_unique<Inert>())));
}

void ClientState::doOnTick() { return; }
