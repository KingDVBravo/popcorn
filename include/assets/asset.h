#ifndef ASSET_H
#define ASSET_H
#include <SDL2/SDL.h>

typedef enum
{
    TILE_GRASS,
    TILE_OTHER
}TileID_n;

SDL_Rect getSpriteFromId(int id);
#endif