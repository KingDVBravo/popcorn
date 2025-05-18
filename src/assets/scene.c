#include "assets/scene.h"
#include "scene.h"

Scene_T* createScene(Tile_t* tiles[2040], Entity_T* entities[32], float playerx, float playery, SDL_Renderer* renderer)
{
    Scene_T* scene = (Scene_T*)calloc(sizeof(Scene_T), 1);
    if (!scene)
    {
        SDL_Log("ERROR: FAILED TO LOAD SCENE");
        return NULL;
    }
    for (int i = 0; i < 2040; i++) 
    {
        scene->tiles[i] = tiles[i];
    }
    for (int i = 0; i < 32; i++)
    {
        scene->entities[i] = entities[i];
    }
    scene->player = createPlayer(playerx, playery, renderer);
    return scene;
}
void clearScene(Scene_T *scene)
{
    for (int i = 0; i < 2040; i++)
    {
        if (scene->tiles[i]) tileClean(scene->tiles[i]);
    }

    for (int i = 0; i < 32; i++)
    {
        if (scene->entities[i]) entityClean(scene->entities[i]);
    }
    playerClean(scene->player);
    free(scene);
}

Scene_T *getSceneFromId(int id, SDL_Renderer *renderer)
{
    if (id > 10)
        return NULL;
    Scene_T* scene;
    switch (id)
    {
        case 0:
            Tile_t* tiles[2040] = {
                tileCreate(0, 0, renderer, 0),
                tileCreate(0, 0, renderer, 0)
            };
            Entity_T entities[32] = {
                entityCreate(0, 0, 0, renderer)
            };
            return createScene(tiles, entities, 0, 0, renderer);
        
    }
}
