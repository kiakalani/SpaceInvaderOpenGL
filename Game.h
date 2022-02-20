#ifndef _GAME_H_
#define _GAME_H_

#include "GameWorld.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.h"
typedef struct game
{
    game_world_t *game_world;
    GLFWwindow *game_window;
    float last_tick;
    camera_t *camera;
    float background[3];
}game_t;

game_t *new_game(uint16_t, uint16_t, char*);

void execute_game(game_t*);

void destroy_game(game_t*);


#endif