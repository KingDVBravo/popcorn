#include "assets/tile.h"
#include "assets/asset.h"

Tile_t* tileCreate(float x, float y, SDL_Renderer* renderer, int id)
{
    if (renderer == NULL)
    {
        SDL_Log("ERROR: RENDERER COULD NOT LOAD");
        return NULL;
    }
    if (x < 0 || y < 0)
    {
        SDL_Log("ERROR: INVALID COORDS");
        return NULL;
    }
    Tile_t* tile = calloc(1, sizeof(Tile_t));
    tile->x = x;
    tile->y = y;
    tile->w = 64;
    tile->h = 64;
    tile->id = id;
    int tilepositon = id * 64;
    tile->frame = (SDL_FRect){
        .x = tile->x,
        .y = tile->y,
        .w = tile->w,
        .h = tile->h
    };
    tile->srcFrame = (SDL_Rect){
        .x = tilepositon,
        .y = 0,
        .w = 64,
        .h = 64
    };
    tile->texture = IMG_LoadTexture(renderer, "../assets/sprites.png");
    if (tile->texture == NULL)
    {
        SDL_Log("ERROR: FAILED TO LOAD TEXTURE: %s", IMG_GetError());
        tileClean(tile);
        return NULL;
    }
    return tile;
}

void tileClean(Tile_t* tile)
{
    if (tile == NULL) 
        return;
    SDL_DestroyTexture(tile->texture);
    free(tile);
}
void tileSetNewTexture(Tile_t* tile, int id)
{
    if (tile == NULL)
    {
        SDL_Log("ERROR: TEXTURE DOES NOT EXIST");
        return;
    }
    if (id > 128)
    {
        SDL_Log("ERROR: ID DOES NOT EXIST");
        return;
    }
    tile->srcFrame = getSpriteFromId(id);
}
