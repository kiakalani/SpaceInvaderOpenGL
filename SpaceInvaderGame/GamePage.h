#ifndef _GAME_PAGE_H_
#define _GAME_PAGE_H_

#include "../GameWorld.h"
typedef struct game_page_components
{
    game_object_t **enemies;
    uint32_t count_enemies, enemies_n;
    game_object_t *player;
    float last_time;
}game_page_components_t;

game_world_t *new_game_page();

void destroy_game_page(game_world_t*);

void update_game_page(game_world_t*);

void game_page_remove_enemy(game_world_t*, game_object_t*);

#endif