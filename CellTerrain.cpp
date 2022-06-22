
#include "CellTerrain.hpp"


CellTerrain::CellTerrain(int x_in, int y_in, int col_in, int row_in, int size_in, bool drawOutline_in)
{
    // fill in the base cell values
    // position
    x = {x_in};
    y = {y_in};
    // indexes
    col = {col_in};
    row = {row_in};
    // size
    size = {size_in};
    // fill color
    cellColor = {DEFAULT_CELL_FILL_COLOR};
    // whether we draw the outline
    drawOutline = {drawOutline_in};

    // fill in the defaults for this type of cell
    height = {DEFAULT_TERRAIN_HEIGHT};
}

// height setter
void CellTerrain::setHeight(double height_in){
    height = height_in;
}

// height getter
double CellTerrain::getHeight(){
    return height;
}