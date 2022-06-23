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

#include <iostream>  // for cout/endl/unique_ptr/make_unique
#include <string>  // so we can use strings
#include "raylib.h"  // since we need this to paint
// we need this so the unique_ptr and
//      make_unique work on windows
#include <memory>

#define DEFAULT_APPSTAGE_TITLE "App"
#define DEFAULT_MARGIN 10
#define DEFAULT_CELLSIZE 20
#define DEFAULT_PAINT_CELL_OUTLINE true

using namespace std;

class AppStage{
    public:
    // dimension variables
    int width;
    int height;
    // title var
    string title;
    
    // constructor
    AppStage();
    // destructor
    virtual ~AppStage();


    /**
     * @brief handles painting the frame of app stage
     * 
     */
    virtual void paint()=0;

    /**
     * @brief Get the desired title from our AppStage instance
     * 
     * (this should be set during constructors)
     * 
     */
    string getDesiredTitle(){
        if(title.length() > 0)
            return title;
        return DEFAULT_APPSTAGE_TITLE;
    }
};

