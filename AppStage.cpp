

#include "AppStage.hpp"
#include "raylib.h"
#include <time.h>


#define DEFAULT_MARGIN 10
#define DEFAULT_CELLSIZE 5
#define DEFAULT_CELLPERIOD 7

#define PAINT_CELL_OUTLINE_BOOL false

#define SEED_INITIALISING_CODE (unsigned)time(NULL)

// define constructor
AppStage::AppStage(int width_in, int height_in)
// initialise the ez members
: width{width_in}, height{height_in},
// generate some grid params
gridMargin {DEFAULT_MARGIN}, cellSize {DEFAULT_CELLSIZE},
// now prepare our seed
seedVal {SEED_INITIALISING_CODE}
{
    // tell app about seed here?
    // TODO
    cout << "#### - USING SEED: " << seedVal << " - ####" << endl;
    // now prepare the grid cells
    int gridRows = ( width-(gridMargin*2))/cellSize;
    int gridCols = (height-(gridMargin*2))/cellSize;
    // generate grid#
    grid = make_unique<Grid>(gridMargin, gridRows,gridCols, cellSize);
    // generate perlin noise
    perlinGenerator = make_unique<Generator>(seedVal);
    // loop throught the grid and effect it
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

