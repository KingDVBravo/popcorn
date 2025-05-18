#include "common.h"
#include "game.h"

int main(void)
{
    Game* game = gameInit();
    gameLoop(game);
    gameExit(game);
}
