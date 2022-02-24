#include "GameWorld.h"

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

void game_world_update_all_game_objects(game_world_t *gw)
{
    for (intmax_t i = gw->game_objects_n - 1; i > -1; --i)
    {
        if (gw->game_objects[i]->update)
            gw->game_objects[i]->update(gw->game_objects[i]);
    }
}

game_world_t *new_game_world()
{
    game_world_t *gw = (game_world_t*)calloc(sizeof(game_world_t), 1);
    gw->game_objects = (game_object_t**) malloc(sizeof(game_object_t*) * (gw->size_game_objects = 1));
    gw->update = game_world_update_all_game_objects;
    gw->free_self = destroy_game_world;
    return gw;
}

void render_game_world(game_world_t *gw, camera_t *c)
{
    float *camera_mat = create_camera_mat4(c);
    for (uintmax_t i = 0; i < gw->game_objects_n; ++i)
    {
        if (gw->game_objects[i]->render)
        gw->game_objects[i]->render(gw->game_objects[i], camera_mat);
    }
    free(camera_mat);
}

void handle_game_world(game_world_t *gw, int32_t type_event, int32_t key)
{
    for (uintmax_t i = 0; i < gw->game_objects_n; ++i)
        if (gw->game_objects[i]->handle)
        gw->game_objects[i]->handle(gw->game_objects[i], type_event, key);
}

void destroy_game_world(game_world_t *gw)
{
    for (uintmax_t i = 0; i < gw->game_objects_n; ++i)
        destroy_game_object(gw->game_objects[i]);
    free(gw->game_objects);
    free(gw);
}

void add_game_object_game_world(game_world_t *gw, game_object_t *go)
{
    if (gw->size_game_objects <= gw->game_objects_n + 1)
        gw->game_objects = (game_object_t**)realloc(gw->game_objects, sizeof(game_object_t*) * (gw->size_game_objects *= 2));

    gw->game_objects[(gw->game_objects_n)++] = go;
}

game_object_t *remove_game_object_game_world(game_world_t *gw, uintmax_t index)
{
    game_object_t *go = gw->game_objects[index];

    for (uintmax_t i = index; i < gw->game_objects_n - 1; ++i)
    {
        gw->game_objects[i] = gw->game_objects[i + 1];
    }

    (gw->game_objects_n)--;

    if (gw->size_game_objects / 2 > gw->game_objects_n)
        gw->game_objects = (game_object_t**)realloc(gw->game_objects, sizeof(game_object_t*) * (gw->size_game_objects /= 2));
    return go;
}


