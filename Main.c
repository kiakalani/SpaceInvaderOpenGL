#include <stdio.h>
#include "Game.h"
#include "GameWorld.h"
#include "SpaceInvaderGame/MainMenu.h"
shape_t *quad_shape = NULL;
shader_t *basic_shader = NULL;
game_t *game = (game_t*)0;
texture_t *bullet_texture = (texture_t*)0;
texture_t *enemy_texture = (texture_t*)0;

int main()
{
    game = new_game(1024, 768, "Title");
    quad_shape = new_quad_shape();
    basic_shader = new_shader("../vert", "../frag");
    game->game_world = new_main_menu();
    bullet_texture = new_texture("../SpaceInvaderGame/Textures/GamePage/Bullet.png");
    enemy_texture = new_texture("../SpaceInvaderGame/Textures/GamePage/Enemy.png");
    execute_game(game);

    destroy_shader(basic_shader);
    destroy_shape(quad_shape);
    destroy_game(game);
    destroy_texture(bullet_texture);
    destroy_texture(enemy_texture);

    return 0;
}