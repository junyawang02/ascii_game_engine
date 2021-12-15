#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../util/posn.h"
#include "movementComponent.h"
#include <map>
#include <memory>
#include <string>

using std::map;
using std::string;
using std::unique_ptr;

class Entity;

class Movement : public MovementComponent {
    map<string, unique_ptr<MovementComponent>> moveMap;
    Posn velocity(const Entity &e) override;

public:
    Movement();
    Movement(unique_ptr<MovementComponent> base);
    void addMovement(string s, unique_ptr<MovementComponent> mov);
    void removeMovement(string s);
    void clearMovement();
};

#endif
