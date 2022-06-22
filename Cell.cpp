
#include "Cell.hpp"


Cell::Cell() :
// position
x {0}, y {0},
// indexes
col {-1}, row {-1},
// size
size {DEFAULT_CELL_SIZE},
// fill color
cellColor {DEFAULT_CELL_FILL_COLOR},
// whether we draw the outline
drawOutline{DEFAULT_CELL_DRAWOUTLINE}
{
    
}

// constructor
Cell::Cell(int x_in, int y_in, int col_in, int row_in, int size_in, bool drawOutline_in) :
// position
x {x_in}, y {y_in},
// indexes
col {col_in}, row {row_in},
// size
size {size_in},
// fill color
cellColor {DEFAULT_CELL_FILL_COLOR},
// whether we draw the outline
drawOutline{drawOutline_in}
{
    // filler = DEFAULT_CELL_FILLER_VAL;
    // nothing here we did it all the other way
}

// destructor
Cell::~Cell(){
    //TODO
}

// paint function
void Cell::paint(){
    // draw fill
    DrawRectangle(x,y,size,size,cellColor);
    if(drawOutline)
        // draw outline
        DrawRectangleLines(x,y,size,size,DARKGRAY);
}

void Cell::setColor(Color color_in){
    cellColor = color_in;
}

int Cell::getPosX(){
    return x;
}
int Cell::getPosY(){
    return y;
}