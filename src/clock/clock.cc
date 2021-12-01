#include "clock.h"

#include <ctime>

Clock::Clock(): time{clock()} {}

bool Clock::tick() {
    clock_t cur = clock();
    if (0.5 <= ((float)difftime(cur, time)) / CLOCKS_PER_SEC) {
        time = cur;
        return true;
    }
    return false;
}