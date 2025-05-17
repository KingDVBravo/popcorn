#include "assets/entity.h"

Entity_T *entityCreate(float x, float y, int id, SDL_Renderer* renderer)
{
    Entity_T* entity = calloc(1, sizeof(Entity_T));
    entity->x = x;
    entity->y = y;
    entity->tile = tileCreate(entity->x, entity->y, renderer, id);
    if (entity->tile == NULL)
    {
        SDL_Log("ERROR: FAILED TO LOAD TILE CORESPONDING TO ENTITY %d", id);
        return;
    }
    return entity;
}
void entityClean(Entity_T* entity)
{
    tileClean(entity->tile);
    free(entity);
    return;
}