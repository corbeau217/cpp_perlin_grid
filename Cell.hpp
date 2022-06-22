#pragma once

#include "raylib.h"


#define DEFAULT_CELL_FILLER_VAL 1.0
#define DEFAULT_CELL_FILL_COLOR WHITE

class Cell{
    public:
    // position vars

    int x;
    int y;
    
    // index vars

    int col;
    int row;

    // size var
    int size;

    // fill color
    Color cellColor;

    // if we draw outline
    bool drawOutline;

    // constructor
    Cell(int x_in, int y_in, int col_in, int row_in, int size_in, bool drawOutline_in);
    ~Cell();

    // paint function
    void paint();

    void setColor(Color color_in);
};

