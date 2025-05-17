#ifndef ENTITY_H
#define ENTITY_H
#include "tile.h"
typedef struct
{
    Tile_t* tile;
    float x, y;
}Entity_T;
Entity_T* entityCreate(float x, float y, int id, SDL_Renderer* renderer);
void entityClean(Entity_T* entity);
#endif