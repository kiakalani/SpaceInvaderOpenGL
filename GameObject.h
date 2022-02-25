#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_
#include <stdint.h>

#include "Shader.h"
#include "Shape.h"
#include "Texture.h"

typedef struct game_object
{
    float position[2];
    float scale[2];
    float rotation;
    void *private_components;
    
    
    struct shape *shape;
    struct shader *shader;
    struct texture *texture;

    void (*render)(struct game_object*, float*);
    char (*handle)(struct game_object*, int32_t, int32_t);
    void (*update)(struct game_object*);

    void (*free_self)(struct game_object*);
} game_object_t;

game_object_t *new_game_object(shape_t*, shader_t*, texture_t*);

void destroy_game_object(game_object_t*);
void game_object_free_self(game_object_t *g);

#endif