#ifndef CLIENT_STATE
#define CLIENT_STATE

class ClientState : public State {
    void doCreate();
    void doOnTick();
};

#endif