#include "assets/asset.h"
const SDL_Rect sprites[128] = {
    [TILE_GRASS] = {0, 0, 64, 64},
};
SDL_Rect getSpriteFromId(int id)
{
    if (id > 128)
        return;
    return sprites[id];
}