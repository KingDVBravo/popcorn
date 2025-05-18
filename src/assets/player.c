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
    return player;
}
void playerUpdate(Player_T* player, float x, float y)
{   
    if (!player)
    {
        SDL_Log("ERROR: PLAYER NOT FOUND");
        return;
    }
    if (!&player->tile->frame)
    {
        SDL_Log("ERROR: PLAYER FRAME NOT FOUND");
    }
    player->tile->frame.x += x;
    player->tile->frame.y += y;
    return;
}
void playerClean(Player_T* player)
{
    tileClean(player->tile);
    free(player);
    return;
}
void playerRender(Player_T *player, SDL_Renderer *renderer)
{
    if (!player)
    {
        SDL_Log("ERROR: FAILED TO LOAD PLAYER (RENDER PLAYER)");
        return;
    }
    if (!renderer)
    {
        SDL_Log("ERROR: FAILED TO LOAD RENDERER (RENDER PLAYER)");
        return;
    }
    SDL_RenderCopyF(renderer, player->tile->texture, &player->tile->srcFrame, &player->tile->frame);
}