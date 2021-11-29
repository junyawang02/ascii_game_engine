#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "line.h"

using std::string;

class View {
public:
    virtual ~View() = default;
    virtual void update() = 0;
    virtual void update(Line line, const string &s) = 0;
    virtual void displayView() = 0;
};

#endif