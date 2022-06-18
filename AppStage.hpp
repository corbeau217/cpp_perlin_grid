/**
 * @file AppStage.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief this is to declutter the App.cpp/App.hpp files
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// header guard to prevent redefining
#pragma once

#include "Grid.hpp"
#include <iostream>  // for cout/endl/unique_ptr/make_unique
#include "Perlin.hpp" // the plagarised perlin machiner

using namespace std;
using namespace Perlin;

class AppStage{
    public:
    // dimension variables
    int width;
    int height;
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
    AppStage(int width_in, int height_in);
    // destructor
    ~AppStage();

    /**
     * @brief handles painting the frame of app stage
     * 
     */
    void paint();
};

