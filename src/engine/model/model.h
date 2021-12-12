#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <string>
#include <vector>

#include "../controller/controller.h"
#include "../util/action.h"
#include "../util/line.h"
#include "../view/view.h"

using std::string;
using std::unique_ptr;
using std::vector;

class Model {
    vector<unique_ptr<View>> views;
    vector<unique_ptr<Controller>> controllers;

protected:
    Action getAction(size_t i);
    vector<Action> getAllActions();

public:
    Model();
    void addView(unique_ptr<View> v);
    void addController(unique_ptr<Controller> c);
    virtual ~Model() = default;
    void updateViews();
    void updateViews(Line line, string s);
    void clearViews();
    void displayViews();
};

#endif