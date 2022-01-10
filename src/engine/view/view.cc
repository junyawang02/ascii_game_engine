#include "view.h"
#include "../util/line.h"
#include <string>

using std::string;

void View::update() { doUpdate(); }

void View::update(Line line, string s) { doUpdate(line, s); }

void View::displayView() { doDisplayView(); }

void View::clear() { doClear(); }
