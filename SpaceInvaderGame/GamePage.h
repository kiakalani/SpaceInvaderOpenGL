#ifndef _GAME_PAGE_H_
#define _GAME_PAGE_H_

#include "../GameWorld.h"
/**
 * @brief <code>game_page_components_t</code> contains the private
 * components that correspond the game page.
 * 
 */
typedef struct game_page_components
{
    game_object_t **enemies;
    uint32_t count_enemies, enemies_n;
    game_object_t *player;
    float last_time;
}game_page_components_t;

/**
 * @brief Creates a new game page
 * 
 * @return game_world_t* 
 */
game_world_t *new_game_page();

/**
 * @brief Deallocates the game page
 * 
 */
void destroy_game_page(game_world_t*);

/**
 * @brief Updates the game page
 * 
 */
void update_game_page(game_world_t*);

/**
 * @brief Removes enemy from game page private components
 * 
 */
void game_page_remove_enemy(game_world_t*, game_object_t*);

#endif