#ifndef CLOCK_H
#define CLOCK_H

#include <ctime>

class Clock {
    clock_t time;

public:
    Clock();
    bool tick();
};

#endif
