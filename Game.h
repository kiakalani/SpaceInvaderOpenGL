#ifndef _GAME_H_
#define _GAME_H_

#include "GameWorld.h"
#include <GLFW/glfw3.h>

typedef struct game
{
    game_world_t *game_world;
    GLFWwindow *game_window;
}game_t;

game_t *new_game();

void execute_game(game_t*);

void destroy_game(game_t*);


#endif