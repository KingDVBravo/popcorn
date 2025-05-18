#ifndef SCENE_H
#define SCENE_H
#include "tile.h"
#include "player.h"
#include "entity.h"
/*
    height = 34
    width = 60
    height * width = 2040
*/
typedef struct 
{
    Tile_t* tiles[2040];
    Entity_T* entities[32]; /* max */
    Player_T* player;

}Scene_T;

Scene_T* createScene(Tile_t* tiles[2040], Entity_T* entities[32], float playerx, float playery, SDL_Renderer* renderer);
void clearScene(Scene_T* scene);
Scene_T* getSceneFromId(int id, SDL_Renderer* renderer);
void renderScene(SDL_Renderer* renderer, Scene_T* scene);
#endif