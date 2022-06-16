

#include "AppStage.hpp"
#include "raylib.h"

#define DEFAULT_MARGIN 10
#define DEFAULT_CELLSIZE 5
#define DEFAULT_CELLPERIOD 7

#define PAINT_CELL_OUTLINE_BOOL false

// define constructor
AppStage::AppStage(int width_in, int height_in){
    // initialise dimension vars
    width = width_in;
    height = height_in;
    // generate grid params
    int gridMargin = DEFAULT_MARGIN;
    int cellSize = DEFAULT_CELLSIZE;
    int gridRows = ( width-(gridMargin*2))/cellSize;
    int gridCols = (height-(gridMargin*2))/cellSize;
    // generate grid
    grid = new Grid(gridMargin, gridRows,gridCols, cellSize);
    // generate perlin noise
    // perlinNoise = new PerlinNoise(gridRows, gridCols, DEFAULT_CELLSIZE*3);
    for(int x = 0; x < gridCols; x++){
        for(int y = 0; y < gridRows; y++){
            // TODO set this up with the new perlin system
            // float *perlinVal = perlinNoise->getPerlinValue(x,y);
            // grid->setCellFill(x,y,perlinVal);
        }
    }
}

// define destructor
AppStage::~AppStage(){
    //TODO
}


void AppStage::paint(){
    grid->paint(PAINT_CELL_OUTLINE_BOOL);
}

