#ifndef BITMAP_H
#define BITMAP_H

#include <vector>
#include <string>
#include "../util/posn.h"

using std::vector;
using std::string;

struct Cell {
    Posn p;
    char c;
    Cell(int x, int y, char c);
};

class Bitmap {
    vector<Cell> theBitmap;
    vector<int> dimensions;

public:
    Bitmap(char c);
    Bitmap(int height, int width, char c);
    Bitmap(vector<Cell> bmap);
    Bitmap(const string &s);
    const vector<Cell> &getBitmap() const;
    const vector<int> &getDimensions() const;
};

#endif
