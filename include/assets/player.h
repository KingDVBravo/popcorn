#ifndef PLAYER_H
#define PLAYER_H
#include "tile.h"
typedef struct
{
    Tile_t* tile;
    float x, y;
}Player_T;

Player_T* createPlayer(float x, float y, SDL_Renderer* renderer);
void playerUpdate(Player_T* player, float x, float y);
void playerClean(Player_T* player);
void playerRender(Player_T* player, SDL_Renderer* renderer);

#endif