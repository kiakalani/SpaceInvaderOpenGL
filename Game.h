#ifndef _GAME_H_
#define _GAME_H_

#include "GameWorld.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.h"
/**
 * @brief Simple API for creation of game instance
 * @author Kia Kalani
 */



#define MOUSE_PRESSED 1
#define MOUSE_RELEASED 2
#define KEY_PRESSED 3
#define KEY_RELEASED 4

/**
 * @brief Contains the window to show, the camera, the mouse position and the color of
 * background.
 * Note: <code>struct game</code> is used for initializing the game and the specified
 * game_world would be added to this structure for execution.
 */
typedef struct game
{
    game_world_t *game_world;
    GLFWwindow *game_window;
    float last_tick;
    camera_t *camera;
    float background[3];
    struct mouse_position *mp;
}game_t;

/**
 * @brief Creates a new game with the width, height and provided
 * title to it.
 * 
 * @return game_t*: a newly initialized <code>game_t</code> instance 
 */
game_t *new_game(uint16_t, uint16_t, char*);

/**
 * @brief executes the main loop of the game.
 * @param game_t*: The <code>game_t</code> to be executed.
 */
void execute_game(game_t*);

/**
 * @brief deallocates the game.
 * @param game_t*: The instance of <code>game_t</code> to deallocate.
 */
void destroy_game(game_t*);

/**
 * @brief Getters of the mouse x and mouse y position that goes
 * from -0.5 to 0.5 according to the position of the mouse in
 * the screen.
 * @param game_t*: The game instance that we want x and y position
 * of the mouse from.
 * @return double: x or y position of the mouse 
 */
double mouse_x_rel(game_t*);
double mouse_y_rel(game_t*);

/**
 * @brief The game instance that would be executed for running
 * the game.
 * 
 */
extern game_t *game;


#endif