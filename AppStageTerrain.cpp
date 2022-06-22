#include "AppStageTerrain.hpp"
#include "App.hpp"
#include "TerrainGrid.hpp"

// define constructor
AppStageTerrain::AppStageTerrain(int width_in, int height_in)
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
    title = "Terrain grid using seed: ";
    title += to_string(seedVal);
    
    // now prepare the grid cells
    int gridCols = ( width-(gridMargin*2))/cellSize;
    int gridRows = (height-(gridMargin*2))/cellSize;

    // generate grid
    grid = make_unique<TerrainGrid>(gridMargin, gridCols,gridRows, cellSize, DEFAULT_PAINT_CELL_OUTLINE);

    // generate perlin noise
    int perlinSize = max<int>(width,height); // to generate a square
    perlin = make_unique<Noise>(perlinSize,perlinSize,DEFAULT_FREQUENCY,DEFAULT_OCTAVES,0.5,seedVal);

    // now update the grid heights off perlin values
    updateGridHeights();

    // say that we havent handled them yet
    handledColors = false;

}

AppStageTerrain::~AppStageTerrain(){
    //TODO
}

/**
 * @brief this handles giving the grid the perlin values
 * 
 */
void AppStageTerrain::updateGridHeights(){
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
            // give the height to grid
            grid->setCellHeight(
                xIdx,yIdx,
                perlinValueAsHeight(currPerlinVal)
                );
        }
    }
}

/**
 * @brief this handles updating the cells with their correct
 *      terrain colours based on their height
 * 
 */
void AppStageTerrain::updateGridColors(){
    // get our grid information
    int gridCols = grid->getCols();
    int gridRows = grid->getRows();
    // loop throught the grid and effect it
    for(int xIdx = 0; xIdx < gridCols; xIdx++){
        for(int yIdx = 0; yIdx < gridRows; yIdx++){
            // get the height at that location
            double currCellHeight = grid->getCellHeight(xIdx,yIdx);
            // give the height to grid
            grid->setCellColor(
                xIdx,yIdx,
                terrainHeightAsColor(currCellHeight)
                );
        }
    }
}


void AppStageTerrain::paint(){
    // having this handled here means we've
    //      resolved our constructor
    if(!handledColors)
        updateGridColors();
    // paint the grid now
    grid->paint();
}

/**
 * @brief handles converting the perlin value to a cell height
 * 
 * @param perlinValue_in : from our perlin object
 * @return double : in the range:
 *          TerrainGrid::minHeight() to TerrainGrid::maxHeight()
 */
double AppStageTerrain::perlinValueAsHeight(double perlinValue_in){
    // get our min and max values
    double minHeight = TerrainGrid::minHeight();
    double maxHeight = TerrainGrid::maxHeight();
    double heightRange = maxHeight-minHeight;
    // now convert the perlin value from (-1 to 1) to (0.0 to heightRange)
    double perlinValInRange = ((perlinValue_in+1)/2.0)*heightRange;
    // add our minimum height
    double cellHeight = minHeight + perlinValInRange;
    // return as cell height
    return cellHeight;
}

Color AppStageTerrain::terrainHeightAsColor(double height_in){
    // get our grid information
    double seaHeight = TerrainGrid::getSeaLevel();
    double minHeight = TerrainGrid::minHeight();
    double maxHeight = TerrainGrid::maxHeight();

    // for the bottom of our range
    double heighestMin = minHeight;
    // check if seaHeight is an option
    if(seaHeight > minHeight){
        // check if below seaLevel
        if(height_in < seaHeight){
            double deeperSeas = (seaHeight-minHeight)/2.0+minHeight;
            if(height_in < deeperSeas)
                return DARKBLUE;
            else return BLUE;
        }
        heighestMin = seaHeight;
    }
    // heigher than sea
    double grassMax = (maxHeight-heighestMin)/3.0 + heighestMin;
    if(height_in < grassMax)
        return GREEN; // grass
    // heigher still
    // we want only the top third of that
    double iceMin = maxHeight - (maxHeight-grassMax)/3.0;
    if(height_in < iceMin)
        return BROWN;
    // otherwise we're ICE
    return GRAY;
    
}

