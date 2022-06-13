/**
 * @file App.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief this defines our raylib app
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// include our header
#include "App.hpp"


// ----------------------------------------
// define static members

App *App::app = nullptr;

void App::start(){
    cout << "[running]: App::start()" << endl;
    App::app = new App();
    App::app->run();
}

// ----------------------------------------
// define instance members

// define our constructor
App::App(){
    // setup dimensions
    appWidth = DEFAULT_WIDTH;
    appHeight = DEFAULT_HEIGHT;
    // setup framerate
    appFramerate = DEFAULT_FRAMERATE;
    // setup default title
    appTitle = DEFAULT_TITLE;
    // setup default background color
    appFrameBackground = DEFAULT_FRAME_BG;
    // set initialisation bool to false
    initialised = false;
    // setup app stage
    appStage = new AppStage(appWidth,appHeight);
}
// define our destructor
App::~App(){
    //TODO
    delete appStage;
}

// define getters

int App::getWidth(){
    return appWidth;
}
int App::getHeight(){
    return appHeight;
}
int App::getFramerate(){
    return appFramerate;
}
string App::getTitle(){
    return appTitle;
}

// define member functions

/**
 * @brief change the apps title
 * 
 */
void App::updateTitle(string newTitle){
    appTitle = newTitle;
    if(initialised)
        SetWindowTitle(newTitle.c_str());
}

/**
 * @brief updates app dimensions
 * 
 */
void App::updateDimensions(int newWidth, int newHeight){
    appWidth = newWidth;
    appHeight = newHeight;
    // check if window initialised
    if(initialised)
        // change the window size
        SetWindowSize(newWidth,newHeight);
}

/**
 * @brief update our app framerate
 * 
 */
void App::updateFramerate(int newFramerate){
    appFramerate = newFramerate;
    if(initialised)
        SetTargetFPS(newFramerate);
}

/**
 * @brief generate the app
 * 
 */
void App::initialise(){
    if(!initialised){
        InitWindow( getWidth(), getHeight(), getTitle().c_str());
        SetTargetFPS( getFramerate() );
        initialised = true;
    }
    else
        reinitialise();
}

/**
 * @brief same as this->initialise(); but for use when
 *      already running
 * 
 */
void App::reinitialise(){
    // change everything back to defaults
    updateDimensions(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    updateFramerate(DEFAULT_FRAMERATE);
    updateTitle(DEFAULT_TITLE);
    // TODO: modify children to default
    appStage = new AppStage(appWidth,appHeight);
}

/**
 * @brief anything needed to be done when the app is closed
 * 
 */
void App::cleanup(){
    //TODO
}

/**
 * @brief paint single frame
 * 
 */
void App::paint(){
    ClearBackground(appFrameBackground);
    // check our appStage is ready for painting
    if(appStage && appStage!=nullptr)
        // hand off for painting
        appStage->paint();
}

/**
 * @brief this is called to run a created App instance
 * 
 */
void App::run(){
    // check if initialised
    if(!initialised)
        initialise();
    
    // handles the draw loop
    while( !WindowShouldClose() ){
        BeginDrawing();
        paint();
        EndDrawing();
    }

    // cleanup the app
    cleanup();
}