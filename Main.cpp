// raylib includes
#include "raylib.h"
// project includes
#include "App.hpp"
// c/c++ includes
#include <string>  // for strings
#include <iostream>  // for cout/endl

using namespace std;


/**
 * @brief main landing point for our program
 * 
 */
int main(){
    cout << "--> Executing Main::main()" << endl;
    
    // start our app
    App::start();

    return 0;
}