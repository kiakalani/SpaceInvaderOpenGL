#ifndef _GAME_WORLD_H_
#define _GAME_WORLD_H_
#include "Camera.h"
#include "GameObject.h"

typedef struct game_world
{
    game_object_t **game_objects;
    uintmax_t size_game_objects, game_objects_n;
    void (*update)(struct game_world*);
    void (*free_self)(struct game_world*);
}game_world_t;


game_world_t *new_game_world();

void render_game_world(game_world_t*, camera_t*);

void handle_game_world(game_world_t*, int32_t, int32_t);

void destroy_game_world(game_world_t*);

void add_game_object_game_world(game_world_t*, game_object_t*);

game_object_t *remove_game_object_game_world(game_world_t*, uintmax_t);

void game_world_update_all_game_objects(game_world_t*);

#endif