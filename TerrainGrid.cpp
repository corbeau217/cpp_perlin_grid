
#include "TerrainGrid.hpp"

// constructor
TerrainGrid::TerrainGrid(int margin_in, int cols_in, int rows_in, int cellSize_in, bool drawCellOutline_in) :
// setup margins
xMargin {margin_in}, yMargin {margin_in},
// set up array bounds
cols {cols_in}, rows {rows_in},
// setup cell size
cellSize {cellSize_in}
{
    // setup cells
    //  memory leak but we're lazy
    cells = {new CellTerrain**[cols]};

    // say if we draw cells
    drawCellOutlines = drawCellOutline_in;

    // loop through and setup
    for(int x = 0; x < cols; x++){
        // memory leak but we're lazy
        cells[x] = new CellTerrain*[rows];
        for(int y = 0; y < rows; y++){
            int xPos = xMargin + x*cellSize;
            int yPos = yMargin + y*cellSize;
            // this has a memory leak bc we're not deleting them afterwards
            cells[x][y] = new CellTerrain(xPos,yPos,x,y,cellSize,drawCellOutlines);
        }
    }

}

// destructor
TerrainGrid::~TerrainGrid(){
    //TODO - should be handling garbage collection
    //      of our cells
}

// paint function
void TerrainGrid::paint(){
    // for each cell, paint it
    for(int x = 0; x < cols; x++)
        for(int y = 0; y < rows; y++)
            get(x,y)->paint();
    
}

// get cell at location
CellTerrain *TerrainGrid::get(int x, int y){
    return cells[x][y];
}

/**
 * @brief Set the color of the cell
 * 
 * @param x : idx
 * @param y : idx
 * @param color_in : raylib color
 */
void TerrainGrid::setCellColor(int x, int y, Color color_in){
    cells[x][y]->setColor(color_in);
}

/**
 * @brief Set the height of a cell
 * 
 * @param xIdx : idx
 * @param yIdx : idx
 * @param height_in : height double (500.0 is sea level)
 */
void TerrainGrid::setCellHeight(int xIdx, int yIdx, double height_in){
    cells[xIdx][yIdx]->setHeight(height_in);
}

/**
 * @brief Get the height value of a cell location
 * 
 * @param xIdx : index
 * @param yIdx : index
 * @return double 
 */
double TerrainGrid::getCellHeight(int xIdx, int yIdx){
    return cells[xIdx][yIdx]->getHeight();
}

// for checking if a location is valid
bool TerrainGrid::validPos(int x, int y){
    if(x >= cols)
        return false;
    if(y >= rows)
        return false;
    return true;
}

// get the UI x pos of a location
int TerrainGrid::getCellPosX(int xIdx, int yIdx){
    return cells[xIdx][yIdx]->getPosX();
}

// get the UI y pos of a location
int TerrainGrid::getCellPosY(int xIdx, int yIdx){
    return cells[xIdx][yIdx]->getPosY();
}

// cols getter
int TerrainGrid::getCols(){
    return cols;
}

// rows getter
int TerrainGrid::getRows(){
    return rows;
}

