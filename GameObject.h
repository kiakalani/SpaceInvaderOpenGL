#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_
#include <stdint.h>

#include "Shader.h"
#include "Shape.h"
#include "Texture.h"
/**
 * @brief Game object definition
 * @author Kia Kalani
 */


/**
 * @brief <code>struct game_object</code> represents the game objects located
 * within the <code>game_world_t</code> structure.
 */
typedef struct game_object
{
    float position[2];
    float scale[2];
    float rotation;

    void *private_components; /* Additional components that a game object might have */
    
    
    struct shape *shape; /* A quad shape for this specific project */
    struct shader *shader; /* Only simple shader is used for this specific scenario */
    struct texture *texture; /* The texture of each game object */

    void (*render)(struct game_object*, float*); /* Invoked when trying to render objects */
    char (*handle)(struct game_object*, int32_t, int32_t); /* Invoked when trying to handle objects */
    void (*update)(struct game_object*); /* Invoked for updating the game object */

    void (*free_self)(struct game_object*); /* Deallocator of the structure */
} game_object_t;

/**
 * @brief Creates a new instance of <code>game_object_t</code> to be added to the <code>game_world_t</code>.
 * @param shape_t*: The shape of the object
 * @param shader_t*: The shader for rendering the object
 * @param texture_t*: The texture of each object.
 * @return game_object_t* 
 */
game_object_t *new_game_object(shape_t*, shader_t*, texture_t*);

/**
 * @brief Deallocates the game object
 * @param game_object_t*: The game object to destroy
 */
void destroy_game_object(game_object_t*);

/**
 * @brief Frees the <code>game_object_t</code> instance
 * 
 * @param game_object_t*: The game object to free
 */
void game_object_free_self(game_object_t*);

#endif