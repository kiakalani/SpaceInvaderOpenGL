#include <stdio.h>
#include "Game.h"
#include "GameWorld.h"
int main()
{
    game_t *game = new_game();
    game->game_world = new_main_menu();
    execute_game(game);

    destroy_game(game);
    return 0;
}