
#include "Grid.hpp"
#include "App.hpp"
#include "AppStage.hpp"

// constructor
Grid::Grid(int margin_in, int cols_in, int rows_in, int cellSize_in) :
// setup margins
xMargin {margin_in}, yMargin {margin_in},
// set up array bounds
cols {cols_in}, rows {rows_in},
// setup cell size
cellSize {cellSize_in}
{
    // setup cells
    cells = {new Cell**[cols]};
    // cells = make_unique<unique_ptr<unique_ptr<Cell>[]>[]>(cols);
    // cells = make_unique<unique_ptr<Cell[]>>[](cols);
    // cells = new Cell**[cols];
    for(int x = 0; x < cols; x++){

        cells[x] = new Cell*[rows];
        // cells.get()[x] = make_unique<unique_ptr<Cell>[]>(rows);
        // *(&cells+x) = new Cell*[rows];
        for(int y = 0; y < rows; y++){
            int xPos = xMargin + x*cellSize;
            int yPos = yMargin + y*cellSize;
            cells[x][y] = new Cell(xPos,yPos,x,y,cellSize);
            // cells[x][y] = make_unique<Cell>(xPos, yPos, x, y, cellSize);
        }
    }
}
// destructor
Grid::~Grid(){
    // // delete our cell pointers
    // for(int x = 0; x < cols; x++){
    //     for(int y = 0; y < rows; y++)
    //         delete cells[x][y];
    //     delete cells[x];
    // }
    // delete cells;
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
void Grid::setCellFill(int x, int y, double fill){
    cells[x][y]->setFill(fill);
}

bool Grid::validPos(int x, int y){
    if(x >= cols)
        return false;
    if(y >= rows)
        return false;
    return true;
}

