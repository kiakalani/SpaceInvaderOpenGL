#include <stdio.h>
#include "Game.h"
#include "GameWorld.h"
int main()
{
    game_t *game = new_game(1024, 768, "Title");
    game->game_world = new_game_world();
    shape_t *quad = new_quad_shape();
    texture_t *tex = new_texture("test.png");
    shader_t *shader = new_shader("./vert", "./frag");
    game_object_t *obj = new_game_object(quad, shader, tex);
    add_game_object_game_world(game->game_world, obj);
    execute_game(game);
    destroy_game(game);
    destroy_shader(shader);
    destroy_shape(quad);
    destroy_texture(tex);
    return 0;
}