
#include "Cell.hpp"
#include "raylib.h"

// constructor
Cell::Cell(int x_in, int y_in, int col_in, int row_in, int size_in){
    // position
    x = x_in;
    y = y_in;
    // indexes
    col = col_in;
    row = row_in;
    // size
    size = size_in;
    // default fill
    fill = 1;
}

// destructor
Cell::~Cell(){
    //TODO
}

// paint function
void Cell::paint(bool drawOutlines){
    unsigned char fillToShade = fill*255;
    Color cellFill = (Color){fillToShade, fillToShade, fillToShade, 255};
    // draw fill
    DrawRectangle(x,y,size,size,cellFill);
    if(drawOutlines)
        // draw outline
        DrawRectangleLines(x,y,size,size,DARKGRAY);
}

void Cell::setFill(float fill_in){
    fill = fill_in;
}

