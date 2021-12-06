#include "inert.h"
#include "../util/posn.h"

class Entity;

Posn Inert::velocity(const Entity &e) { return Posn{0, 0}; }
