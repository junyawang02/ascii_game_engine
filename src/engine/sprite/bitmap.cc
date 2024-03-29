#include "bitmap.h"
#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::tuple;
using std::vector;

Cell::Cell(int x, int y, char c) : p{Posn{x, y}}, c{c} {}

Bitmap::Bitmap(char c) {
    theBitmap.push_back(Cell{0, 0, c});
    dimensions = vector<int>{0, 0, 0, 0};
}

Bitmap::Bitmap(int height, int width, char c) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            theBitmap.push_back(Cell{j, i, c});
    }
    dimensions = vector<int>{0, height - 1, width - 1, 0};
}

Bitmap::Bitmap(const string &s) {
    int x = 0;
    int y = 0;
    int maxX = 0;
    for (const auto &c : s) {
        if (c == '\n') {
            if (x > maxX)
                maxX = x;
            x = 0;
            ++y;
        } else {
            theBitmap.push_back(Cell{x, y, c});
            ++x;
        }
    }
    dimensions = vector<int>{0, y, maxX, 0};
}

Bitmap::Bitmap(vector<Cell> bmap) : theBitmap{bmap}, dimensions{vector<int>{0, 0, 0, 0}} {
    for (auto &cell : theBitmap) {
        if (cell.p.x > dimensions[2])
            dimensions[2] = cell.p.x;
        if (cell.p.x < dimensions[3])
            dimensions[3] = cell.p.x;
        if (cell.p.y > dimensions[1])
            dimensions[1] = cell.p.y;
        if (cell.p.y < dimensions[0])
            dimensions[0] = cell.p.y;
    }
}

const vector<Cell> &Bitmap::getBitmap() const { return theBitmap; }

const vector<int> &Bitmap::getDimensions() const { return dimensions; }
