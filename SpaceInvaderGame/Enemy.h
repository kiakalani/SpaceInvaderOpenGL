#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "../GameObject.h"
/**
 * @brief <code>enemy_components_t</code> contains the private'
 * components of enemy game objects.
 * @author Kia Kalani
 * 
 */
typedef struct enemy_components
{
    game_object_t *player;
    // Things like the damage of the enemies could go here
}enemy_components_t;

/**
 * @brief Creates a new enemy at a random position
 * 
 * @return game_object_t* 
 */
game_object_t *new_enemy(game_object_t*);

/**
 * @brief Deallocates the enemy
 * 
 */
void destroy_enemy(game_object_t*);

/**
 * @brief Updates the enemy game object
 * 
 */
void enemy_update(game_object_t*);

#endif