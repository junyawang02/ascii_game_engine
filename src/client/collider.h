#ifndef COLLIDER_H
#define COLLIDER_H

#include "../util/visitor.h"

class ClientEntity;

using Collider = Visitor<ClientEntity>;

#endif
