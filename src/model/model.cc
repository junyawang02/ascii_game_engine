#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "model.h"
#include "../controller/controller.h"
#include "../util/action.h"
#include "../util/line.h"
#include "../view/view.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

Model::Model() {}

void Model::addView(std::unique_ptr<View> v) {
    views.emplace_back(std::move(v));
}

void Model::addController(std::unique_ptr<Controller> c) {
    controllers.emplace_back(std::move(c));
}

Action Model::getAction(size_t i) {
    if (i >= controllers.size()) {
        const string warn{"Index of controller is out of bounds."};
        cout << warn << endl;
        return Action::INVALID;
    }
    return controllers[i]->getAction();
}

vector<Action> Model::getAllActions() {
    vector<Action> v{controllers.size()};
    for (size_t i = 0; i < controllers.size(); ++i) {
        v[i] = controllers[i]->getAction();
    }
    return v;
}

void Model::updateViews() {
    for (auto &v : views)
        v->update();
}

void Model::updateViews(Line line, const string &s) {
    for (auto &v : views)
        v->update(line, s);
}

void Model::displayViews() {
    for (auto &v : views) {
        v->displayView();
    }
}
