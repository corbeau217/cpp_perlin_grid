

#include "AppStage.hpp"
#include "raylib.h"

// define constructor
AppStage::AppStage(int width_in, int height_in){
    // initialise dimension vars
    width = width_in;
    height = height_in;
    // generate grid
    grid = new Grid(width, height);
}

// define destructor
AppStage::~AppStage(){
    //TODO
}


void AppStage::paint(){
    grid->paint(false);
}

