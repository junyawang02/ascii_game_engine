#include "state.h"

void State::create() {
    doCreate();
}

void State::onTick() {
    doOnTick();
}
