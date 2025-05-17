#ifndef TILE_H
#define TILE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct 
{
    float x, y, w, h;
    SDL_Texture* texture;
    SDL_FRect frame;
    SDL_Rect srcFrame;
    int id;
}Tile_t;

Tile_t* tileCreate(float x, float y, SDL_Renderer* renderer, int id);
void tileClean(Tile_t* tile);
void tileSetNewTexture(Tile_t* tile, int id);
#endif