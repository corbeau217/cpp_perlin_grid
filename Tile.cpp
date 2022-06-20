

// include our header
#include "Tile.hpp"

// so we dont need to retype the `tile::`
using namespace tile;

// Tile class here

Tile::Tile(const char *name_in, Color color_in){
    // TODO - constructor for tiles
    name = name_in;
    tileColor = color_in;
}

// TileList class here

TileList::TileList(){
    n = 0;
    m = DEFAULT_TILELIST_SIZE;
    tiles = new Tile*[m];
}

TileList *TileList::add(Tile *tile_in){
    // dont have space
    if(n>=m)
        growList();
    // now add it to the location
    tiles[n++] = tile_in;
    // for builder pattern
    return this;
}

void TileList::growList(){
    // TODO - increase list size
}