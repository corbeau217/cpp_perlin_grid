// header guard
#pragma once

#include "CellTerrain.hpp"
#include <iostream>  // for cout/endl/unique_ptr/make_unique

#define TERRAIN_SEA_HEIGHT DEFAULT_TERRAIN_HEIGHT
#define TERRAIN_MIN_HEIGHT 0.0 // ocean floor
#define TERRAIN_MAX_HEIGHT 1500.0 // maximum height

// saves typing std::
using namespace std;

class TerrainGrid{
    public:
    // margins
    int xMargin;
    int yMargin;
    // counts
    int cols;
    int rows;
    // cell size
    int cellSize;
    // cells
    //   memory leaked format, need to fix it later
    CellTerrain ***cells;
    // bool for if we draw outlines
    bool drawCellOutlines;

    // constructor
    TerrainGrid(int margin_in, int cols_in, int rows_in, int cellSize_in, bool drawCellOutline_in);
    // destructor
    ~TerrainGrid();

    // paint function
    void paint();

    // get cell at location
    CellTerrain *get(int xIdx, int yIdx);

    /**
     * @brief Set the color of the cell
     * 
     * @param xIdx : idx
     * @param yIdx : idx
     * @param color_in : raylib color
     */
    void setCellColor(int xIdx, int yIdx, Color color_in);

    /**
     * @brief Set the height of a cell
     * 
     * @param xIdx : idx
     * @param yIdx : idx
     * @param height_in : height double (500.0 is sea level)
     */
    void setCellHeight(int xIdx, int yIdx, double height_in);

    /**
     * @brief Get the height value of a cell location
     * 
     * @param xIdx : index
     * @param yIdx : index
     * @return double 
     */
    double getCellHeight(int xIdx, int yIdx);

    // for checking if a location is valid
    bool validPos(int xIdx, int yIdx);

    // get the UI x pos of a location
    int getCellPosX(int xIdx, int yIdx);
    // get the UI y pos of a location
    int getCellPosY(int xIdx, int yIdx);

    // cols getter
    int getCols();
    // rows getter
    int getRows();



    // sea level getter
    static double getSeaLevel(){
        return TERRAIN_SEA_HEIGHT;
    }
    // min height getter
    static double minHeight(){
        return TERRAIN_MIN_HEIGHT;
    }
    // max height getter
    static double maxHeight(){
        return TERRAIN_MAX_HEIGHT;
    }
};

