#include "assets/player.h"

Player_T* createPlayer(float x, float y, SDL_Renderer* renderer)
{
    Player_T* player = calloc(sizeof(Player_T), 1);
    if (!player)
    {
        SDL_Log("ERROR: FAILED TO LOAD PLAYER");
        return NULL;
    }
    player->x = x;
    player->y = y;
    player->tile = tileCreate(player->x, player->y, renderer, 0);
    if (!player->tile)
    {
        SDL_Log("ERROR: FAILED TO CHOP PLAYER TILE");
        return NULL;
    }
}
void playerUpdate(SDL_Event event, Player_T* player, float x, float y)
{   
    
    
}
void playerClean(Player_T* player)
{
    tileClean(player->tile);
    free(player);
    return;
}