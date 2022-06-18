

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
    int gridCols = ( width-(gridMargin*2))/cellSize;
    int gridRows = (height-(gridMargin*2))/cellSize;
    // generate grid#
    grid = make_unique<Grid>(gridMargin, gridCols,gridRows, cellSize);
    // generate perlin noise
    perlin = make_unique<Noise>(max<int>(width,height),max<int>(width,height),6.5,3u,0.5,seedVal);
    // loop throught the grid and effect it
    
    for(int xIdx = 0; xIdx < gridCols; xIdx++){
        for(int yIdx = 0; yIdx < gridRows; yIdx++){
            // if(!grid->validPos(xIdx,yIdx))
            //     break;
            // TODO set this up with the new perlin system
            int xPos = gridMargin + xIdx*cellSize;
            int yPos = gridMargin + yIdx*cellSize;
            double currFill = perlin->get(xPos,yPos);
            grid->get(xIdx,yIdx)->setFill(&currFill);
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

