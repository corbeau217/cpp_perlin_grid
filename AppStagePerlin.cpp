# include "AppStagePerlin.hpp"
#include "App.hpp"

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
    grid = make_unique<Grid>(gridMargin, gridCols,gridRows, cellSize, DEFAULT_PAINT_CELL_OUTLINE);

    // generate perlin noise
    int perlinSize = max<int>(width,height); // to generate a square
    perlin = make_unique<Noise>(perlinSize,perlinSize,DEFAULT_FREQUENCY,DEFAULT_OCTAVES,0.5,seedVal);

    // now update the grid
    updateGrid();
}

AppStagePerlin::~AppStagePerlin(){
    //TODO
}

/**
 * @brief this handles giving the grid the perlin values
 * 
 */
void AppStagePerlin::updateGrid(){
    // get our grid information
    int gridCols = grid->getCols();
    int gridRows = grid->getRows();
    // loop throught the grid and effect it
    for(int xIdx = 0; xIdx < gridCols; xIdx++){
        for(int yIdx = 0; yIdx < gridRows; yIdx++){
            // get our grid position of each cell
            int xPos = grid->getCellPosX(xIdx,yIdx);
            int yPos = grid->getCellPosY(xIdx,yIdx);
            // get the fill at that location
            double currPerlinVal = perlin->get(xPos,yPos);
            // give the fill to grid
            grid->setCellColor(
                xIdx,yIdx,
                perlinValueAsColor(currPerlinVal)
                );
        }
    }
}

void AppStagePerlin::paint(){
    grid->paint();
}

Color AppStagePerlin::perlinValueAsColor(double perlinValue_in){
    // get our filler out of 255
    double fillToShade = ((perlinValue_in+1)/2.0)*255.0;
    // convert to unsigned char
    unsigned char finalFillValue = fillToShade;
    // return as color
    return (Color){finalFillValue, finalFillValue, finalFillValue, 255};
}

