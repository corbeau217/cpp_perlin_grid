
#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

#include "Seeder.hpp"
#include "raylib.h"
#include <cmath>

class PerlinNoise{
    public:
    // resolution vars
    int pixel_width;
    int pixel_height;
    // gradient spacing
    int pixel_period;
    // gradient grid vars
    int gradientGrid_cols;
    int gradientGrid_rows;
    // gradient vector grid
    Vector2 ***gradientGrid;
    // seeder vars
    Seeder *seeder;
    unsigned seederOrigin;
    // use fade bool
    bool useFadeFunction;

    // constructor without seed
    PerlinNoise(int pixel_width_in, int pixel_height_in,
                int pixel_period_in);
    // constructor reusing a seed
    PerlinNoise(int pixel_width_in, int pixel_height_in,
                int pixel_period_in, unsigned seederOrigin_in);
    // destructor
    ~PerlinNoise();

    /**
     * @brief Get the perlin value at the location
     * 
     * @param x 
     * @param y 
     * @return float 
     */
    float getPerlinValue(int x, int y);

    /**
     * @brief generates a vector using the current seed
     * 
     * @return Vector2* 
     */
    Vector2 *getNextRandomVector();


    float fadeFunc(float x);

    float dotProdFunc(float x1, float y1, float x2, float y2);

};

#endif