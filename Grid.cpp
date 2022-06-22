
#include "Grid.hpp"
#include "App.hpp"
#include "AppStage.hpp"

// constructor
Grid::Grid(int margin_in, int cols_in, int rows_in, int cellSize_in, bool drawCellOutline_in) :
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

    // say if we draw cells
    drawCellOutlines = drawCellOutline_in;

    // loop through and setup
    for(int x = 0; x < cols; x++){

        cells[x] = new Cell*[rows];
        // cells.get()[x] = make_unique<unique_ptr<Cell>[]>(rows);
        // *(&cells+x) = new Cell*[rows];
        for(int y = 0; y < rows; y++){
            int xPos = xMargin + x*cellSize;
            int yPos = yMargin + y*cellSize;
            cells[x][y] = new Cell(xPos,yPos,x,y,cellSize,drawCellOutlines);
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
void Grid::paint(){
    for(int x = 0; x < cols; x++)
        for(int y = 0; y < rows; y++)
            get(x,y)->paint();
    
}

// get cell at location
Cell *Grid::get(int x, int y){
    return cells[x][y];
}

/**
 * @brief Set the color of the cell
 * 
 * @param x : idx
 * @param y : idx
 * @param color_in : raylib color
 */
void Grid::setCellColor(int x, int y, Color color_in){
    cells[x][y]->setColor(color_in);
}

bool Grid::validPos(int x, int y){
    if(x >= cols)
        return false;
    if(y >= rows)
        return false;
    return true;
}

int Grid::getCellPosX(int xIdx, int yIdx){
    return cells[xIdx][yIdx]->getPosX();
}
int Grid::getCellPosY(int xIdx, int yIdx){
    return cells[xIdx][yIdx]->getPosY();
}

int Grid::getCols(){
    return cols;
}
int Grid::getRows(){
    return rows;
}