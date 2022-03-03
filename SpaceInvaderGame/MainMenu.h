#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_
#include "../GameWorld.h"
/**
 * 
 * @brief Creates a new game world that contains the components of
 * the main menu.
 * 
 * @return game_world_t* 
 * @author Kia Kalani
 */
game_world_t *new_main_menu();

/**
 * @brief Deallocates the main menu
 * 
 */
void destroy_main_menu(game_world_t*);
#endif