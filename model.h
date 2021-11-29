#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <string>
#include <vector>

#include "action.h"
#include "controller.h"
#include "line.h"
#include "view.h"

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
    void updateViews(Line line, const string &s);
    void displayViews();
};

#endif