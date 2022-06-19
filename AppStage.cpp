

#include "AppStage.hpp"
#include "raylib.h"
#include <time.h>


#define DEFAULT_MARGIN 10
#define DEFAULT_CELLSIZE 30

#define DEFAULT_FREQUENCY 3.0 // double - zoom
#define DEFAULT_OCTAVES 1u //unsigned int
#define DEFAULT_PERSISTENCE 0.5 // double - fall off of octaves

#define PAINT_CELL_OUTLINE_BOOL false

#define SEED_GENERATE_NEW (unsigned)time(NULL)
#define SEED_INITIALISING_CODE SEED_GENERATE_NEW

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
    int perlinSize = max<int>(width,height); // to generate a square
    perlin = make_unique<Noise>(perlinSize,perlinSize,DEFAULT_FREQUENCY,DEFAULT_OCTAVES,0.5,seedVal);
    // loop throught the grid and effect it
    
    for(int xIdx = 0; xIdx < gridCols; xIdx++){
        for(int yIdx = 0; yIdx < gridRows; yIdx++){
            // if(!grid->validPos(xIdx,yIdx))
            //     break;
            // TODO set this up with the new perlin system
            int xPos = gridMargin + xIdx*cellSize;
            int yPos = gridMargin + yIdx*cellSize;
            double currFill = perlin->get(xPos,yPos);
            grid->setCellFill(xIdx,yIdx,currFill);
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

