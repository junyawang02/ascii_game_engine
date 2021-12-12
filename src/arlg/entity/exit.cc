#include "exit.h"
#include "../../engine/sprite/animated.h"
#include "../../engine/sprite/bitmap.h"
#include "../../engine/util/acceptor.h"
#include "../../engine/util/line.h"
#include "../../engine/util/posn.h"
#include "../collider/exitCollider.h"
#include <memory>
#include <string>
#include <vector>

using std::make_unique;
using std::pair;
using std::string;
using std::vector;

Exit::Exit(int x, int y) : Acceptor{x, y, make_unique<Animated>(vector<Bitmap>{Bitmap{'e'}, Bitmap{'E'}}),
                                    make_unique<ExitCollider>(this)} {}

pair<bool, bool> Exit::doEndState() {
    if (isFinish)
        return pair<bool, bool>{true, true};
    else
        return pair<bool, bool>{false, false};
}

pair<Line, string> Exit::doUpdateStatus() {
    if (isOpen) {
        const string openMessage = "The exit is open!";
        return pair<Line, string>{Line::L3, openMessage};
    }
    return pair<Line, string>{Line::NA, ""};
}

void Exit::open() { 
    isOpen = true;
    nextForm(); 
}

void Exit::finish() { isFinish = true; }
