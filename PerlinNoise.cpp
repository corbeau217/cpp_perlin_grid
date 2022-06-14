
// include out header
#include "PerlinNoise.hpp"

#define USING_FADEFUNC false

// constructor without seed origin
PerlinNoise::PerlinNoise(int pixel_width_in, int pixel_height_in, int pixel_period_in){
    // setup seeder
    seeder = new Seeder();
    seederOrigin = seeder->seedOrigin;
    // setup pixel vars
    pixel_width = pixel_width_in;
    pixel_height = pixel_height_in;
    // setup grid spacing
    pixel_period = pixel_period_in;
    // setup gradient grid vars
    gradientGrid_cols = (int)(ceilf(pixel_width / pixel_period) + 1);
    gradientGrid_rows = (int)(ceilf(pixel_height / pixel_period) + 1);
    // setup gradient grid
    gradientGrid = new Vector2**[gradientGrid_cols];
    for(int x = 0; x < gradientGrid_cols; x++){
        gradientGrid[x] = new Vector2*[gradientGrid_rows];
        for(int y = 0; y < gradientGrid_rows; y++){
            gradientGrid[x][y] = getNextRandomVector();
        }
    }
    // setup use fade bool
    useFadeFunction = USING_FADEFUNC;
}

// constructor with seed origin
PerlinNoise::PerlinNoise(int pixel_width_in, int pixel_height_in, int pixel_period_in, unsigned seederOrigin_in){
    // setup seeder
    seederOrigin = seederOrigin_in;
    seeder = new Seeder(seederOrigin);
    // setup pixel vars
    pixel_width = pixel_width_in;
    pixel_height = pixel_height_in;
    // setup grid spacing
    pixel_period = pixel_period_in;
    // setup gradient grid vars
    gradientGrid_cols = (int)(ceilf(pixel_width / pixel_period) + 1);
    gradientGrid_rows = (int)(ceilf(pixel_height / pixel_period) + 1);
    // setup gradient grid
    gradientGrid = new Vector2**[gradientGrid_cols];
    for(int x = 0; x < gradientGrid_cols; x++){
        gradientGrid[x] = new Vector2*[gradientGrid_rows];
        for(int y = 0; y < gradientGrid_rows; y++){
            gradientGrid[x][y] = getNextRandomVector();
        }
    }
    // setup use fade bool
    useFadeFunction = USING_FADEFUNC;
}

// destructor
PerlinNoise::~PerlinNoise(){
    delete seeder;
    // delete the pointers
    for(int x = 0; x < gradientGrid_cols; x++){
        for(int y = 0; y < gradientGrid_rows; y++){
            delete gradientGrid[x][y];
        }
        delete gradientGrid[x];
    }
    delete gradientGrid;
}

/**
 * @brief Get the perlin value at the location
 * 
 * @param x 
 * @param y 
 * @return float : 0.0 - 1.0
 */
float PerlinNoise::getPerlinValue(int x, int y){
    // coords of cell
    int cell_x = (int)floorf(x / pixel_period);
    int cell_y = (int)floorf(y / pixel_period);
    // Relative coordinate of the point in the cell, normalized so that they are in [0, 1]
    float relative_x = (float)(x - cell_x * pixel_period) / (float)pixel_period;
    float relative_y = (float)(y - cell_y * pixel_period) / (float)pixel_period;
    // fade
    if(useFadeFunction){
        relative_x = fadeFunc(relative_x);
        relative_y = fadeFunc(relative_y);
    }
    // gradient vectors to use
    Vector2 *top_left_gradient = gradientGrid[cell_x     ][cell_y    ];
    Vector2 *top_right_gradient = gradientGrid[cell_x + 1][cell_y    ];
    Vector2 *bot_left_gradient = gradientGrid[cell_x     ][cell_y + 1];
    Vector2 *bot_right_gradient = gradientGrid[cell_x + 1][cell_y + 1];
    
    // calculate contributions
    float top_left_contribution = dotProdFunc(
        top_left_gradient->x,
        top_left_gradient->y,
        relative_x,
        relative_y
    );
    float top_right_contribution = dotProdFunc(
        top_right_gradient->x,
        top_right_gradient->y,
        relative_x - 1,
        relative_y
    );
    float bot_left_contribution = dotProdFunc(
        bot_left_gradient->x,
        bot_left_gradient->y,
        relative_x,
        relative_y - 1
    );
    float bot_right_contribution = dotProdFunc(
        bot_right_gradient->x,
        bot_right_gradient->y,
        relative_x - 1,
        relative_y - 1
    );
    // lerp
    float top_lerp = lerp(top_left_contribution, top_right_contribution, relative_x);
    float bot_lerp = lerp(bot_left_contribution, bot_right_contribution, relative_x);
    // final lerp
    float final_value = lerp(top_lerp, bot_lerp, relative_y);
    return final_value / (sqrt(2) / 2);
}

/**
 * @brief generates a vector using the current seed
 * 
 * @return Vector2* 
 */
Vector2 *PerlinNoise::getNextRandomVector(){
    // get our random val
    float randomFloat = (float)(seeder->getNextRandom())/(float)RAND_MAX;
    // get our random angle
    float angle = randomFloat * 2 * (float)M_PI;
    // now generate a vector based on angle
    Vector2 *result = new Vector2{cosf(angle),sinf(angle)};
    // then return
    return result;
}

float PerlinNoise::fadeFunc(float x){
    return 6 * pow(x, 5) - 15 * pow(x, 4) + 10 * pow(x, 3);
    
}

float PerlinNoise::dotProdFunc(float x1, float y1, float x2, float y2){
    return x1 * x2 + y1 * y2;
}