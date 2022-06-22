# include "AppStagePerlin.hpp"
#include "raylib.h"
#include <time.h>
#include "App.hpp"


#define DEFAULT_MARGIN 10
#define DEFAULT_CELLSIZE 30

#define DEFAULT_FREQUENCY 3.0 // double - zoom
#define DEFAULT_OCTAVES 1u //unsigned int
#define DEFAULT_PERSISTENCE 0.5 // double - fall off of octaves

#define PAINT_CELL_OUTLINE_BOOL false

#define SEED_GENERATE_NEW (unsigned)time(NULL)
#define SEED_INITIALISING_CODE SEED_GENERATE_NEW


// define constructor
AppStagePerlin::AppStagePerlin(int width_in, int height_in)
// generate some grid params
: gridMargin {DEFAULT_MARGIN}, cellSize {DEFAULT_CELLSIZE},
// now prepare our seed
seedVal {SEED_INITIALISING_CODE}
{
    // initialise the ez members
    width = {width_in};
    height = {height_in};

    // tell app about seed here
    cout << "#### - USING SEED: " << seedVal << " - ####" << endl;

    // this is handled by the app once constructor resolves
    title = "Perlin grid using seed: ";
    title += to_string(seedVal);
    
    // now prepare the grid cells
    int gridCols = ( width-(gridMargin*2))/cellSize;
    int gridRows = (height-(gridMargin*2))/cellSize;

    // generate grid
    grid = make_unique<Grid>(gridMargin, gridCols,gridRows, cellSize, PAINT_CELL_OUTLINE_BOOL);

    // generate perlin noise
    int perlinSize = max<int>(width,height); // to generate a square
    perlin = make_unique<Noise>(perlinSize,perlinSize,DEFAULT_FREQUENCY,DEFAULT_OCTAVES,0.5,seedVal);

    // loop throught the grid and effect it
    for(int xIdx = 0; xIdx < gridCols; xIdx++){
        for(int yIdx = 0; yIdx < gridRows; yIdx++){
            // get our grid position of each cell
            int xPos = gridMargin + xIdx*cellSize;
            int yPos = gridMargin + yIdx*cellSize;
            // get the fill at that location
            double currFill = perlin->get(xPos,yPos);
            // now convert to color
            // get our filler out of 255
            double fillToShade = ((currFill+1)/2.0)*255.0;
            // convert to unsigned char
            unsigned char finalFillValue = fillToShade;
            // get as color
            Color cellFill = (Color){finalFillValue, finalFillValue, finalFillValue, 255};
            // give the fill to grid
            grid->setCellColor(xIdx,yIdx,cellFill);
        }
    }
}

AppStagePerlin::~AppStagePerlin(){
    //TODO
}

void AppStagePerlin::paint(){
    grid->paint();
}