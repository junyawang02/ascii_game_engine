#include "clientState.h"
#include "../entity/clientEntity.h"
#include "../sprite/bitmap.h"
#include "../sprite/still.h"
#include "../sprite/animated.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::vector;


void ClientState::doCreate() { 
    addEntity(make_unique<ClientEntity>(1, 1, make_unique<Still>(Bitmap{'c'})));
    addEntity(make_unique<ClientEntity>(2, 5, make_unique<Still>(Bitmap{10, 5, 'w'})));
    addEntity(make_unique<ClientEntity>(40, 10, make_unique<Still>(Bitmap{vector<Cell>{{0, 0, 'S'}, {0, 1, 's'}, {1, 1, 's'}, {2, 1, 's'}}})));
    addEntity(make_unique<ClientEntity>(40, 10, make_unique<Animated>(vector<Bitmap> {Bitmap{'c'}, Bitmap{'C'}})));
}

void ClientState::doOnTick() { return; }
