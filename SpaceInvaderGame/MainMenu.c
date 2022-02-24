#include "MainMenu.h"
#include "../Game.h"
extern shape_t *quad_shape;
extern shader_t *basic_shader;

texture_t *main_menu_start_button_texture = (texture_t*)0;
texture_t *main_menu_quit_button_texture = (texture_t*)0;

void main_menu_handle_quit_button(game_object_t *go, int action, int key)
{
    if (action == MOUSE_RELEASED)
    {
        double mousex = mouse_x_rel(game);
        double mousey = mouse_y_rel(game);
        if (mousex > go->position[0] - go->scale[0] && mousex < go->position[0] + go->scale[0])
        {
            if (mousey > go->position[1] + go->scale[1] && mousey < go->position[1] + go->scale[1])
            {
                glfwSetWindowShouldClose(game->game_window, 1);
            }
        }
    }
}

game_world_t *new_main_menu()
{
    game_world_t *world = new_game_world();

    world->free_self = destroy_main_menu;
    
    main_menu_start_button_texture = new_texture("Textures/MainMenu/StartButton.png");
    main_menu_quit_button_texture = new_texture("Textures/MainMenu/QuitButton.png");

    game_object_t *play_button = new_game_object(quad_shape, basic_shader, main_menu_start_button_texture);
    add_game_object_game_world(world, play_button);


    game_object_t *quit_button = new_game_object(quad_shape, basic_shader, main_menu_quit_button_texture);
    quit_button->handle = main_menu_handle_quit_button;

    add_game_object_game_world(world, quit_button);



    return world;
}

void destroy_main_menu(game_world_t *world)
{
    texture_t *rem = main_menu_start_button_texture;
    main_menu_start_button_texture = NULL;
    destroy_texture(rem);

    rem = main_menu_quit_button_texture;
    main_menu_quit_button_texture = NULL;
    destroy_texture(rem);

    destroy_game_world(world);
}
