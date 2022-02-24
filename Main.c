#include <stdio.h>
#include "Game.h"
#include "GameWorld.h"
game_t *game = (game_t*)0;
void test_update(game_object_t *g)
{
    g->position[0] = mouse_x_rel(game) * 100.0f;
    g->position[1] =   mouse_y_rel(game) * 100.0f;
    
    g->rotation += 0.01f;
}

void test_handle(game_object_t *go, int action, int key)
{
    if (action == KEY_PRESSED)
    {
        switch (key)
        {
            case GLFW_KEY_A:
                game->camera->position[0] -= 0.01f;
                break;
            case GLFW_KEY_D:
                game->camera->position[0] += 0.01f;
                break;
            case GLFW_KEY_W:
                game->camera->position[1] += 0.01f;
                break;
            case GLFW_KEY_S:
                game->camera->position[1] -= 0.01f;
                break;
        }
    }
}
int main()
{
    game = new_game(1024, 768, "Title");
    game->game_world = new_game_world();
    shape_t *quad = new_quad_shape();
    texture_t *tex = new_texture("../test.png");
    shader_t *shader = new_shader("../vert", "../frag");
    game_object_t *obj = new_game_object(quad, shader, tex);
    obj->update = test_update;
    obj->scale[0] = 10.0f;
    obj->scale[1] = 10.0f;
    obj->position[0] = -50.0f;
    obj->position[1] = -50.0f;
    obj->handle = test_handle;

    add_game_object_game_world(game->game_world, obj);
    execute_game(game);
    destroy_game(game);
    destroy_shader(shader);
    destroy_shape(quad);
    destroy_texture(tex);
    return 0;
}