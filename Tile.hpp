// header guard
#pragma once

#include "raylib.h"
#include <string>

#define DEFAULT_TILELIST_SIZE 10
#define DEFAULT_TILELIST_GROWTH 5

namespace tile {
    // Tile class
    class Tile {
        public:
        // name var
        const char *name;
        // color var
        Color tileColor;

        // constructor
        Tile(const char *name_in, Color color_in);
    };

    // TileList class
    class TileList {
        public:
        // our tile list
        Tile **tiles;

        int m; // max tiles
        int n; // current tile number

        // constructor
        TileList();

        // helper members

        // adder
        TileList *add(Tile *tile_in);

        // getter
        Tile *get(int idx);

        // increase list size
        void growList();
        
    };
}