#include "game.h"
#include "assets/tile.h"

void gameRender(Game* game)
{
    if (game == NULL)
        SDL_Log("ERROR: Game not intialized!");
    if (game->renderer == NULL)
        SDL_Log("ERROR: Renderer not intialized!");
    if (game->window == NULL)
        SDL_Log("ERROR: Window not intialized!");
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderClear(game->renderer);
    SDL_RenderCopyF(game->renderer, game->tile->texture, &game->tile->srcFrame, &game->tile->frame);
    /*
    float window_width = 1080.0f;
    float window_height = 720.0f;
    float tile_w = (float)game->tile->frame.w;
    float tile_h = (float)game->tile->frame.h;
    for (float y = 0.0f; y < window_height; y += tile_h) {
        for (float x = 0.0f; x < window_width; x += tile_w) {
            SDL_FRect destRect = { x, y, tile_w, tile_h };
            SDL_RenderCopyF(game->renderer, game->tile->texture, &game->tile->srcFrame, &destRect);
        }
    }
    */
    SDL_RenderPresent(game->renderer);

}
Game* gameInit()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        SDL_Log("ERROR: SDL COULD NOT INITIALIZE: %s", SDL_GetError());

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) == 0)
        SDL_Log("ERROR: SDL COULD NOT INITIALIZE IMAGE: %s", IMG_GetError());
    Game* game = calloc(1, sizeof(Game));
    if (!game) 
    {
        SDL_Log("ERROR: COULD NOT ALLOCATE GAME");
        return NULL;
    }

    game->window = SDL_CreateWindow("Popcorn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
    if (game->window == NULL)
    {
        SDL_Log("ERROR: COULD NOT INITIALIZE WINDOW: %s", SDL_GetError());
        free(game);
        return NULL;
    }
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_TARGETTEXTURE);
    if (game->renderer == NULL)
    {
        SDL_Log("ERROR: COULD NOT INITIALIZE RENDERER: %s", SDL_GetError());
        free(game);
        return NULL;
    }
    game->tile = tileCreate(0, 0, game->renderer, 2);
    game->running = true;
    return game;
}

void gameLoop(Game* game)
{
    if (game == NULL)
        SDL_Log("ERROR: GAME DOES NOT EXIST");
    if (game->window == NULL)
        SDL_Log("ERROR: COULD NOT FIND WINDOW");
    if (game->renderer == NULL)
        SDL_Log("ERROR: COULD NOT FIND RENDERER");
    while (game->running)
    {
        /*
            main game loop
        */
        gameRender(game);
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game->running = false;
            }
        }
    }
    SDL_Delay(16);
}
void gameExit(Game* game)
{
    if (!game) return;

    tileClean(game->tile);

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    free(game);

    IMG_Quit();
    SDL_Quit();
}