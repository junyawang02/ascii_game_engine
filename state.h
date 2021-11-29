#ifndef STATE_H
#define STATE_H

class State {
    virtual void doCreate() = 0;
    virtual void doOnTick() = 0;

public:
    void create();
    void onTick();
};

#endif