#include "myRandom.h"
#include <time.h>

int myRandom(int min, int max) {
    return min + ( rand() % ( max - min + 1 ) );
}
