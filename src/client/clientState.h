#ifndef CLIENT_STATE
#define CLIENT_STATE

#include "../physics/physics.h"
#include "../state/state.h"

class ClientState : public State {
    void doCreate() override;
    void doOnTick() override;

public:
    ClientState(unique_ptr<Physics> p);
};

#endif