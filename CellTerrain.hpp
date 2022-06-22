#pragma once

#include "Cell.hpp"
#include "raylib.h"

#define DEFAULT_TERRAIN_HEIGHT 500.0 // sea level

class CellTerrain : public Cell{
    public:
    double height;

    // constructor
    CellTerrain(int x_in, int y_in, int col_in, int row_in, int size_in, bool drawOutline_in);
    ~CellTerrain();

    // height setter
    void setHeight(double height_in);

    // height getter
    double getHeight();
};

