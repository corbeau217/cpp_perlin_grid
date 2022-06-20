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
    
    // constructor
    AppStage();
    // destructor
    virtual ~AppStage();


    /**
     * @brief handles painting the frame of app stage
     * 
     */
    virtual void paint()=0;
};

