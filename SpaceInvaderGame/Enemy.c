#include "Enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Game.h"
extern shader_t *basic_shader;
extern shape_t *quad_shape;

extern texture_t *enemy_texture;

game_object_t *new_enemy(game_object_t *player)
{
    game_object_t *e = new_game_object(quad_shape, basic_shader, enemy_texture);
    enemy_components_t *comps = (enemy_components_t*)malloc(sizeof(enemy_components_t));
    e->position[1] = 50.0f;
    e->position[0] = ((float)rand() / RAND_MAX) * 100.0f - 50.0f;
    e->scale[0] = 5.0f;
    e->scale[1] = 5.0f;
    comps->player = player;
    e->private_components = (void*)comps;
    e->update = enemy_update;
    e->free_self = destroy_enemy;
    return e;
}


void enemy_update(game_object_t *enemy)
{
    enemy->position[1] -= 0.3f;
    if (enemy->position[1] < -60.0f)
    {
        remove_game_object_game_world_by_item(game->game_world, enemy);
        enemy->free_self(enemy);
        return;
    }

    game_object_t *player = ((enemy_components_t*)(enemy->private_components))->player;
    if (enemy->position[0] - enemy->scale[0] * 0.5 < player->position[0] + player->scale[0] * 0.5&&
        enemy->position[0] + enemy->scale[0] * 0.5 > player->position[0] - player->scale[0] * 0.5)
    if (enemy->position[1] - enemy->scale[1] * 0.5 < player->position[1] + player->scale[1] * 0.5&&
        enemy->position[1] + enemy->scale[1] * 0.5 > player->position[1] - player->scale[1] * 0.5)
        {
            // Closing the window; aka game over
            glfwSetWindowShouldClose(game->game_window, 1);
            return;
        }
    
}


void destroy_enemy(game_object_t *e)
{
    free(e->private_components);
    game_object_free_self(e);
}