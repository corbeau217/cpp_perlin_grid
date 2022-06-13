
#include "Grid.hpp"

// constructor
Grid::Grid(int width_in, int height_in){
    // setup margins
    xMargin = DEFAULT_MARGIN;
    yMargin = DEFAULT_MARGIN;
    // setup cell size
    cellSize = DEFAULT_CELLSIZE;
    // set up array bounds
    cols = ( width_in-(xMargin*2))/cellSize;
    rows = (height_in-(yMargin*2))/cellSize;
    // setup cells
    cells = new Cell**[cols];
    for(int x = 0; x < cols; x++){
        cells[x] = new Cell*[rows];
        for(int y = 0; y < rows; y++){
            int xPos = xMargin + x*cellSize;
            int yPos = yMargin + y*cellSize;
            cells[x][y] = new Cell(xPos, yPos, x, y, cellSize);
        }
    }
}
// destructor
Grid::~Grid(){
    // delete our cell pointers
    for(int x = 0; x < cols; x++){
        for(int y = 0; y < rows; y++)
            delete cells[x][y];
        delete cells[x];
    }
    delete cells;
}

// paint function
void Grid::paint(bool drawOutlines){
    for(int x = 0; x < cols; x++)
        for(int y = 0; y < rows; y++)
            get(x,y)->paint(drawOutlines);
    
}

// get cell at location
Cell *Grid::get(int x, int y){
    return cells[x][y];
}

/**
 * @brief Set the cell at location to be filled by value
 * 
 * @param x 
 * @param y 
 * @param fill : 0.0 - 1.0
 */
void Grid::setCellFill(int x, int y, float fill){
    get(x,y)->setFill(fill);
}


