// header guard
#ifndef GRID_HPP
#define GRID_HPP

#include "Cell.hpp"


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

    // constructor
    Grid(int margin_in, int cols_in, int rows_in, int cellSize_in);
    // destructor
    ~Grid();

    // paint function
    void paint(bool drawOutlines);

    // get cell at location
    Cell *get(int x, int y);

    /**
     * @brief Set the cell at location to be filled by value
     * 
     * @param x 
     * @param y 
     * @param fill : 0.0 - 1.0
     */
    void setCellFill(int x, int y, float *fill);
};

#endif