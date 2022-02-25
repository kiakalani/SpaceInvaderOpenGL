#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "../GameObject.h"
typedef struct enemy_components
{
    game_object_t *player;
    // Things like the damage of the enemies could go here
}enemy_components_t;

game_object_t *new_enemy(game_object_t*);

void destroy_enemy(game_object_t*);

void enemy_update(game_object_t*);

#endif