#ifndef _BULLET_H_
#define _BULLET_H_
#include "../GameObject.h"
/**
 * @brief <code>bullet_components_t</code> contains the private
 * components that are related to the bullet's logic.
 * @author Kia Kalani
 */
typedef struct bullet_components
{
    float creation_time;
    float longevity;
    game_object_t *owner;
    
}bullet_components_t;

/**
 * @brief Creates a new bullet
 * 
 * @return game_object_t* 
 */
game_object_t *new_bullet(game_object_t*, float);
/**
 * @brief Deallocates the bullet
 * 
 */
void destroy_bullet(game_object_t*);
/**
 * @brief Updates the bullet
 * 
 */
void bullet_update(game_object_t*);
#endif