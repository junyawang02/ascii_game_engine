#include "control.h"
#include "../entity/entity.h"
#include "../util/action.h"
#include "../util/posn.h"
#include "movementComponent.h"
#include <map>
#include <vector>

using std::map;
using std::vector;

const map<Action, Posn> defaultMap{
    {Action::UP, Posn{0, -1}},
    {Action::DOWN, Posn{0, 1}},
    {Action::RIGHT, Posn{1, 0}},
    {Action::LEFT, Posn{-1, 0}}
};

Control::Control(vector<size_t> con, map<Action, Posn> m) : MovementComponent{}, controlNums{con}, moves{m} {}

Control::Control(vector<size_t> con) : MovementComponent{}, controlNums{con}, moves{defaultMap} {}

Control::Control(size_t con, map<Action, Posn> m) : MovementComponent{}, controlNums{vector<size_t>{con}}, moves{m} {}

Control::Control(size_t con) : MovementComponent{}, controlNums{vector<size_t>{con}}, moves{defaultMap} {}

Posn Control::velocity(const Entity &e) {
    const vector<Action> &acts = e.getActions();
    Posn vel = Posn{0, 0};
    for (auto &n : controlNums) {
        if (n < acts.size()) {
            Action a = acts[n];
            vel += moves[a];
            Posn future = e.getPos() + vel;
            if (future.x < 1)
                vel.x += 1 - future.x;
            if (future.x > 78)
                vel.x += 78 - future.x;
            if (future.y < 1)
                vel.y += 1 - future.y;
            if (future.y > 20)
                vel.y += 20 - future.y;
        }
    }
    return vel;
}
