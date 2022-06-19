
#include "Cell.hpp"
#include "raylib.h"

#define DEFAULT_CELL_FILLER_VAL 1.0

// constructor
Cell::Cell(int x_in, int y_in, int col_in, int row_in, int size_in) :
// position
x {x_in}, y {y_in},
// indexes
col {col_in}, row {row_in},
// size
size {size_in}
{
    filler = DEFAULT_CELL_FILLER_VAL;
    // nothing here we did it all the other way
}

// destructor
Cell::~Cell(){
    //TODO
}

// paint function
void Cell::paint(bool drawOutlines){
    double fillToShade = filler*255.0;
    unsigned char finalFillValue = fillToShade;
    Color cellFill = (Color){finalFillValue, finalFillValue, finalFillValue, 255};
    // draw fill
    DrawRectangle(x,y,size,size,cellFill);
    if(drawOutlines)
        // draw outline
        DrawRectangleLines(x,y,size,size,DARKGRAY);
}

void Cell::setFill(double fill_in){
    filler = (fill_in+1)/2.0;
}

