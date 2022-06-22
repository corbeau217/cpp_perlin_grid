// header guard
#pragma once

#include "AppStage.hpp"

#include "TerrainGrid.hpp"
#include <iostream>  // for cout/endl/unique_ptr/make_unique
#include "Perlin.hpp" // the plagarised perlin machiner

using namespace std;
using namespace Perlin;

// inherit from AppStage
class AppStageTerrain : public AppStage {
    public:
    // grid params
    int gridMargin;
    int cellSize;

    // our seed that we use
    unsigned int seedVal;

    // grid instance
    unique_ptr<TerrainGrid> grid;
    
    // perlin noise instance
    unique_ptr<Noise> perlin;

    // if we've handled the colors of our grid
    bool handledColors;
    /* TODO: we could have this check each draw if there was
     *      an update that needs to be handled
     *      and then have it handled in the updating of 
     *      cell heights that it tells us we need to recalculate
     *      etc. or maybe have each cell individually keep track
     *      of this, then loop over the cells if we detect an update
     * 
     *      could use check/parity bits for speeding this up
     */

    // constructor
    AppStageTerrain(int width_in, int height_in);
    // destructor
    virtual ~AppStageTerrain();

    /**
     * @brief this handles giving the grid the perlin values
     * 
     */
    void updateGridHeights();

    /**
     * @brief this handles updating the cells with their correct
     *      terrain colours based on their height
     * 
     */
    void updateGridColors();

    /**
     * @brief handles painting the frame of app stage
     * 
     */
    void paint();

    /**
     * @brief handles converting the perlin value to a cell height
     * 
     * @param perlinValue_in : from our perlin object
     * @return double : in the range:
     *          TerrainGrid::minHeight() to TerrainGrid::maxHeight()
     */
    static double perlinValueAsHeight(double perlinValue_in);

    /**
     * @brief for converting the terrain height to a cell color
     * 
     * @param height_in 
     * @return Color 
     */
    static Color terrainHeightAsColor(double height_in);
};