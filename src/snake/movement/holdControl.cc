#include "holdControl.h"
#include "../../engine/entity/entity.h"
#include "../../engine/movement/movementComponent.h"
#include "../../engine/util/action.h"
#include "../../engine/util/posn.h"
#include <map>
#include <vector>

using std::map;
using std::vector;

const map<Action, Posn> defaultMap{
    {Action::UP, Posn{0, -1}},
    {Action::DOWN, Posn{0, 1}},
    {Action::RIGHT, Posn{1, 0}},
    {Action::LEFT, Posn{-1, 0}}};

HoldControl::HoldControl(size_t con, map<Action, Posn> m) : MovementComponent{}, controlNum{con}, moves{m}, current{Action::RIGHT} {}

HoldControl::HoldControl(size_t con) : MovementComponent{}, controlNum{con}, moves{defaultMap}, current{Action::RIGHT} {}

Posn HoldControl::velocity(const Entity &e) {
    const vector<Action> &acts = e.getActions();
    Posn vel = Posn{0, 0};
    Action a;
    if (controlNum < acts.size())
        a = acts[controlNum];
    else 
        a = Action::NONE;
    if (a != Action::NONE)
        current = a;
    vel = moves[current];
    Posn future = e.getPos() + vel;
    if (future.x < 1)
        vel.x += 1 - future.x;
    if (future.x > 78)
        vel.x += 78 - future.x;
    if (future.y < 1)
        vel.y += 1 - future.y;
    if (future.y > 20)
        vel.y += 20 - future.y;
    return vel;
}
