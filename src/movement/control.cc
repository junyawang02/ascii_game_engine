#include "control.h"
#include "../entity/entity.h"
#include "../util/action.h"
#include "../util/posn.h"
#include "movement.h"
#include "movementDecorator.h"
#include <map>
#include <memory>
#include <vector>

using std::map;
using std::unique_ptr;
using std::vector;

const map<Action, Posn> defaultMap{
    {Action::UP, Posn{0, -1}},
    {Action::DOWN, Posn{0, 1}},
    {Action::RIGHT, Posn{1, 0}},
    {Action::LEFT, Posn{-1, 0}}};

Control::Control(vector<size_t> con, map<Action, Posn> m, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, controlNums{con}, moves{m} {}

Control::Control(vector<size_t> con, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, controlNums{con}, moves{defaultMap} {}

Control::Control(size_t con, map<Action, Posn> m, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, controlNums{vector<size_t>{con}}, moves{m} {}

Control::Control(size_t con, unique_ptr<Movement> c) : MovementDecorator{std::move(c)}, controlNums{vector<size_t>{con}}, moves{defaultMap} {}

Posn Control::velocity(const Entity &e) {
    const vector<Action> &acts = e.getActions();
    Posn vel = Posn{0, 0};
    for (auto &n : controlNums) {
        if (n < acts.size()) {
            Action a = acts[n];
            vel += moves[a];
        }
    }
    return vel;
}
