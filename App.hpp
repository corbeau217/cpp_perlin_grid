/**
 * @file App.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief this handles the raylib app
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// header guard to stop redefining
#pragma once

// raylib includes here
#include "raylib.h"
// project includes here
#include "AppStage.hpp"
#include "AppStagePerlin.hpp"
#include "AppStageTerrain.hpp"
// c/c++ includes here
#include <string>  // for strings
#include <iostream>  // for cout/endl/unique_ptr/make_unique
// we need this so the unique_ptr and
//      make_unique work on windows
#include <memory>

// saves typing std::
using namespace std;

// definitions
#define DEFAULT_WIDTH 1024
#define DEFAULT_HEIGHT 720
#define DEFAULT_FRAMERATE 15
#define DEFAULT_TITLE "C++ perlin noise grid project"
// how many frames after a refresh before we can do another
#define REFRESH_FRAME_COOLDOWN 5 
#define APP_REFRESH_KEY KEY_SPACE

// color definitions
#define DEFAULT_FRAME_BG GRAY


class App{
    public:
    // ----------------------------------------
    // static members
    static unique_ptr<App> app;

    static void start();

    // ----------------------------------------
    // instance members

    // dimension variables
    int appWidth;
    int appHeight;
    // framerate var
    int appFramerate;
    // window title
    string appTitle;
    // initialisation bool
    bool initialised;
    // color vars
    Color appFrameBackground;

    // stage var
    unique_ptr<AppStage> appStage;

    // reinitialising tracking variable

    // a rudimentary timer variable for keeping track of
    //  how long since our last refresh
    int framesUntilRefreshCooldown;




    // constructor
    App();
    // destructor
    ~App();

    // getters

    int getWidth();
    int getHeight();
    int getFramerate();
    string getTitle();

    /**
     * @brief change the apps title
     * 
     */
    void updateTitle(string newTitle);

    /**
     * @brief updates app dimensions
     * 
     */
    void updateDimensions(int newWidth, int newHeight);

    /**
     * @brief update our app framerate
     * 
     */
    void updateFramerate(int newFramerate);

    /**
     * @brief generate the app
     * 
     */
    void initialise();

    /**
     * @brief same as this->initialise(); but for use when
     *      already running
     * 
     */
    void reinitialise();

    /**
     * @brief anything needed to be done when the app is closed
     * 
     */
    void cleanup();

    /**
     * @brief paint single frame
     * 
     */
    void paint();

    /**
     * @brief this is called to run a created App instance
     * 
     */
    void run();

    /**
     * @brief checks if we should refresh
     * 
     * @return true : APP_REFRESH_KEY down and not cooldown
     * @return false : otherwise
     */
    bool desireRefresh();

    // handles ticking down the refresh cooldown
    void tickRefreshCooldown();
};
