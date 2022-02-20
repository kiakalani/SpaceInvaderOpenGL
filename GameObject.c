#include "GameObject.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <math.h>
#include <string.h>

void game_object_free_self(game_object_t*);
void game_object_render(game_object_t*, float*);
float *calculate_game_object_transformation(game_object_t*);
void apply_scale(float*, float*);


game_object_t *new_game_object(shape_t *shape, shader_t *shader, texture_t *texture)
{
    game_object_t *obj = (game_object_t*)calloc(sizeof(game_object_t), 1);
    obj->scale[0] = 1.0f;
    obj->scale[1] = 1.0f;
    obj->free_self = game_object_free_self;
    obj->render = game_object_render;
    obj->shape = shape;
    obj->shader = shader;
    obj->texture = texture;

    return obj;
}

void game_object_free_self(game_object_t *g)
{
    free(g);
}

void game_object_render(game_object_t *g, float *camera)
{
    if (!g->texture || !g->shape || !g->shader) return;
    use_shader(g->shader);
    use_shape(g->shape, g->shader);
    use_texture(g->texture, g->shader);

    int32_t mat_add = get_uniform_address(g->shader, "camera_matrix");
    glUniformMatrix4fv(mat_add, 1, GL_FALSE, camera);

    float *transformation = calculate_game_object_transformation(g);

    mat_add = 0;
    mat_add = get_uniform_address(g->shader, "transformation_matrix");

    glUniformMatrix4fv(mat_add, 1, GL_FALSE, transformation);

    glDrawElements(GL_TRIANGLES, g->shape->size, GL_UNSIGNED_INT, 0);
    
    free(transformation);
}

float *calculate_game_object_transformation(game_object_t *g)
{
    float *transformation = (float*)calloc(sizeof(float), 16);

    transformation[0] = cos(g->rotation);
    transformation[1] = sin(g->rotation);
    transformation[4] = -sin(g->rotation);
    transformation[5] = cos(g->rotation);
    transformation[10] = 1.0f;
    transformation[12] = g->position[0];
    transformation[13] = g->position[1];
    transformation[15] = 1.0f; 

    apply_scale(transformation, g->scale);

    return transformation;
}

void apply_scale(float *trans, float *scale)
{
    float sc_mat[16];
    memset(sc_mat, 0, sizeof(sc_mat));
    sc_mat[0] = scale[0];
    sc_mat[5] = scale[1];
    sc_mat[10] = 1.0f;
    sc_mat[15] = 1.0f;
    float result[16];

    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            result[4 * r + c] = 0.0f;
            for (int i = 0; i < 4; ++i)
            {
                result[4 * r + c] += trans[r * 4 + i] * sc_mat[i * 4 + c];
            }
        }
    }
    
    memcpy(trans, result, sizeof(sc_mat));
}

void destroy_game_object(game_object_t *g)
{
    g->free_self(g);
}
