#include "Bullet.h"
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Game.h"
#include "GamePage.h"
extern shape_t *quad_shape;
extern shader_t *basic_shader;
extern texture_t *bullet_texture;

game_object_t *new_bullet(game_object_t *player, float longevity)
{
    game_object_t *b = new_game_object(quad_shape, basic_shader, bullet_texture);
    b->private_components = (void*)malloc(sizeof(bullet_components_t));
    bullet_components_t *bcomp = (bullet_components_t*)b->private_components;
    bcomp->creation_time = glfwGetTime();
    bcomp->longevity = longevity;
    b->free_self = destroy_bullet;
    b->update = bullet_update;

    b->scale[0] = 3.0f;
    b->scale[1] = 3.0f;
    b->position[0] = player->position[0];
    b->position[1] = player->position[1] + 5.0f;
}


void bullet_update(game_object_t *b)
{
    bullet_components_t *bcomp = (bullet_components_t*)b->private_components;

    if (glfwGetTime() - bcomp->creation_time > bcomp->longevity)
    {
        remove_game_object_game_world_by_item(game->game_world, b);
        b->free_self(b);
        return;
    }

    game_page_components_t *gpcomps = (game_page_components_t*)(game->game_world->private_components);

    for (intmax_t i = 0; i < gpcomps->enemies_n; ++i)
    {
        game_object_t *enemy = gpcomps->enemies[i];
        if (!enemy) continue;
        if (enemy->position[0] - enemy->scale[0] * 0.5 < b->position[0] + b->scale[0] * 0.5&&
            enemy->position[0] + enemy->scale[0] * 0.5 > b->position[0] - b->scale[0] * 0.5)
        if (enemy->position[1] - enemy->scale[1] * 0.5 < b->position[1] + b->scale[1] * 0.5&&
            enemy->position[1] + enemy->scale[1] * 0.5 > b->position[1] - b->scale[1] * 0.5)
            {
                game_page_remove_enemy(game->game_world, enemy);
                remove_game_object_game_world_by_item(game->game_world, enemy);
                remove_game_object_game_world_by_item(game->game_world, b);
                b->free_self(b);
                enemy->free_self(enemy);
                return;
            }
    }

    b->position[1] += 0.3f;
}

extern void game_object_free_self(game_object_t*);
void destroy_bullet(game_object_t *go)
{
    free(go->private_components);
    game_object_free_self(go);
}