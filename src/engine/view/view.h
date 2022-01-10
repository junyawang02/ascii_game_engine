#ifndef VIEW_H
#define VIEW_H

#include "../util/line.h"
#include <string>

using std::string;

class View {
    virtual void doUpdate() = 0;
    virtual void doUpdate(Line line, string s) = 0;
    virtual void doDisplayView() = 0;
    virtual void doClear() = 0;

public:
    virtual ~View() = default;
    void update();
    void update(Line line, string s);
    void displayView();
    void clear();
};

#endif
