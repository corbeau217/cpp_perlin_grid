// header guard
#pragma once

#include "AppStage.hpp"

#include "Grid.hpp"
#include <iostream>  // for cout/endl/unique_ptr/make_unique
#include "Perlin.hpp" // the plagarised perlin machiner

using namespace std;
using namespace Perlin;

// inherit from AppStage
class AppStagePerlin : public AppStage {
    public:
    // grid params
    int gridMargin;
    int cellSize;

    // our seed that we use
    unsigned int seedVal;

    // grid instance
    unique_ptr<Grid> grid;
    
    // perlin noise instance
    unique_ptr<Noise> perlin;

    // constructor
    AppStagePerlin(int width_in, int height_in);
    // destructor
    virtual ~AppStagePerlin();

    /**
     * @brief handles painting the frame of app stage
     * 
     */
    void paint();
};