// header guard
#pragma once

#include "Cell.hpp"
#include <iostream>  // for cout/endl/unique_ptr/make_unique

// saves typing std::
using namespace std;

class Grid{
    public:
    // margins
    int xMargin;
    int yMargin;
    // counts
    int cols;
    int rows;
    // cell size
    int cellSize;
    // cells
    Cell ***cells;
    // bool for if we draw outlines
    bool drawCellOutlines;

    // constructor
    Grid(int margin_in, int cols_in, int rows_in, int cellSize_in, bool drawCellOutline_in);
    // destructor
    ~Grid();

    // paint function
    void paint();

    // get cell at location
    Cell *get(int x, int y);

    /**
     * @brief Set the color of the cell
     * 
     * @param x : idx
     * @param y : idx
     * @param color_in : raylib color
     */
    void setCellColor(int x, int y, Color color_in);

    bool validPos(int x, int y);
};

