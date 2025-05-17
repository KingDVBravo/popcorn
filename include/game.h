#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include "assets/tile.h"

typedef struct
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    Tile_t* tile;
}Game;
void gameRender( Game* game);
Game* gameInit();
void gameLoop( Game* game);
void gameExit( Game* game);
void gameControls( SDL_Event event, Game* game );
#endif