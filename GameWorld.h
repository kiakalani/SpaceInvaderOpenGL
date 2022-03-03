#ifndef _GAME_WORLD_H_
#define _GAME_WORLD_H_
#include "Camera.h"
#include "GameObject.h"
/**
 * @brief <code>game_world_t</code> is the defintion of the game world
 * containing all of the game objects in a given world
 * @author Kia Kalani
 * 
 */
typedef struct game_world
{
    game_object_t **game_objects;
    uintmax_t size_game_objects, game_objects_n;
    void (*update)(struct game_world*);
    void (*free_self)(struct game_world*);
    void *private_components;
}game_world_t;


/**
 * @brief Creates a new game world
 * 
 * @return game_world_t* 
 */
game_world_t *new_game_world();

/**
 * @brief Renders the game world
 * 
 */
void render_game_world(game_world_t*, camera_t*);

/**
 * @brief Handles the game world
 * 
 */
void handle_game_world(game_world_t*, int32_t, int32_t);

/**
 * @brief Deallocates the game world
 * 
 */
void destroy_game_world(game_world_t*);

/**
 * @brief Adds a game object to the game world.
 * 
 */
void add_game_object_game_world(game_world_t*, game_object_t*);

/**
 * @brief Removes the game object from the game world
 * 
 * @return game_object_t* 
 */
game_object_t *remove_game_object_game_world(game_world_t*, uintmax_t);

/**
 * @brief Remove the game object by its index.
 * 
 * @return game_object_t* 
 */
game_object_t *remove_game_object_game_world_by_item(game_world_t*, game_object_t*);

/**
 * @brief Calls update on all game objects in the world.
 * 
 */
void game_world_update_all_game_objects(game_world_t*);

#endif