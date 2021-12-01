#include "bitmap.h"
#include <tuple>
#include <vector>

using std::tuple;
using std::vector;

Cell::Cell(int x, int y, char c): p{Posn{x, y}}, c{c} {}

Bitmap::Bitmap(char c) {
    theBitmap.push_back(Cell(0, 0, c));
}

Bitmap::Bitmap(int height, int width, char c) {
    for (int i = 0 ; i < height ; ++i) {
        for (int j = 0 ; j < width ; ++j)
            theBitmap.push_back(Cell(j, i, c));
    }
}

Bitmap::Bitmap(vector<Cell> bmap) : theBitmap{bmap} {}

const vector<Cell> &Bitmap::getBitmap() const {
    return theBitmap;
}
