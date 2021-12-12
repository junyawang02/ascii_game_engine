#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "../util/line.h"

using std::string;

class View {
public:
    virtual ~View() = default;
    virtual void update() = 0;
    virtual void update(Line line, string s) = 0;
    virtual void displayView() = 0;
    virtual void clear() = 0;
};

#endif