#include "GamePage.h"
#include "../Game.h"
#include "Bullet.h"
#include <stdlib.h>
#include "Enemy.h"
extern shape_t *quad_shape;
extern shader_t *basic_shader;
texture_t *player_texture = NULL;

void game_page_update_player(game_object_t *p)
{
    p->position[0] = mouse_x_rel(game) * 100.0f;
}

void game_page_update_bullet(game_object_t *b)
{
    b->position[1] += 0.5f;
}

char game_page_handle_player(game_object_t *p, int action, int key)
{
    if (action == MOUSE_RELEASED)
    {
        add_game_object_game_world(game->game_world, new_bullet(p, 5.0f));
    }

    return 1;
}

void update_game_page(game_world_t *world)
{
    game_page_components_t *comps = (game_page_components_t*)world->private_components;
    if (glfwGetTime() - comps->last_time > 3.0f) // Add an enemy every three seconds
    {
        if (!comps->enemies || comps->count_enemies == 0)
        {
            comps->enemies = (game_object_t**)malloc(sizeof(game_object_t*) * (comps->count_enemies = 8));

        }
        else if (comps->enemies_n + 1 >= comps->count_enemies)
        {
            comps->enemies = (game_object_t**)realloc(comps->enemies, sizeof(game_object_t*) * (comps->count_enemies *= 2));
        }
        game_object_t *enemy = new_enemy(comps->player);

        comps->enemies[comps->enemies_n++] = enemy;

        comps->last_time = glfwGetTime();
        add_game_object_game_world(world, enemy);
    }

    game_world_update_all_game_objects(world);
}

void game_page_remove_enemy(game_world_t *w, game_object_t *e)
{
    game_page_components_t *comps = (game_page_components_t*)w->private_components;
    for (uintmax_t i = 0; i < comps->enemies_n; ++i)
    {
        if (comps->enemies[i] == e)
        {
            for (uintmax_t j = i; j < comps->enemies_n -1; ++j)
                comps->enemies[i] = comps->enemies[i + 1];
            (comps->enemies_n)--;
            return;
        }
    }
}

game_world_t *new_game_page()
{
    game_world_t *world = new_game_world();
    world->free_self = destroy_game_page;
    world->update = update_game_page;
    world->private_components = (void*)calloc(sizeof(game_page_components_t), 1);
    game_page_components_t *comps = (game_page_components_t*)world->private_components;
    comps->last_time = glfwGetTime();
    player_texture = new_texture("../SpaceInvaderGame/Textures/GamePage/Player.png");
    game_object_t *player = new_game_object(quad_shape, basic_shader, player_texture);
    comps->player = player;
    comps->enemies = (game_object_t**)calloc(sizeof(game_object_t*), (comps->count_enemies = 8));
    player->update = game_page_update_player;
    player->handle = game_page_handle_player;
    player->scale[0] = 5.0f;
    player->scale[1] = 10.0f;
    player->position[1] = -35.0f;
    add_game_object_game_world(world, player);
    return world;
}

void destroy_game_page(game_world_t *gw)
{
    game_page_components_t *comps = (game_page_components_t*)gw->private_components;
    if (comps->enemies) free(comps->enemies);
    free(comps);
    destroy_game_world(gw);
}