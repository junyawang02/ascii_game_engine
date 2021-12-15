#include "arlg/game/arlg.h"

int main(int argc, char *argv[]) {
    ARLG theGame{};
    if (argc > 1) {
        int level = atoi(argv[1]);
        if (level >= 2 && level <= 6)
            theGame.skipToLevel(level);
    }
}
