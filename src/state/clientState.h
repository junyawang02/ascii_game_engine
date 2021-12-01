#ifndef CLIENT_STATE
#define CLIENT_STATE

#include "state.h"

class ClientState : public State {
    void doCreate() override;
    void doOnTick() override;
};

#endif