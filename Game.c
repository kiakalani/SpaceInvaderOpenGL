#include "Game.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

void on_resize(GLFWwindow *win, int width, int height);

game_t *new_game(uint16_t width, uint16_t height, char *title)
{
    if (!glfwInit())
    {
        glfwTerminate();
        return (game_t*)(uint64_t)(printf("Error initializing GLFW\n") && 0);
    }

    game_t *game = (game_t*)calloc(sizeof(game_t), 1);
    game->game_window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!game->game_window)
    {
        glfwTerminate();
        free(game);
        return (game_t*)(uint64_t)(printf("Error initializing The Display\n") && 0);
    }

    glfwMakeContextCurrent(game->game_window);
    glewExperimental = 1;
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        free(game);
        return (game_t*)(uint64_t)(printf("Error initializing GLEW\n") && 0);
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    game->camera = new_camera();

    glViewport(0, 0, (int)width, (int)height);

    glfwSetWindowUserPointer(game->game_window, (void*)game);

    glfwSetFramebufferSizeCallback(game->game_window, on_resize);

    return game;
}

void execute_game(game_t *g)
{
    while (!glfwWindowShouldClose(g->game_window))
    {
        float current_time = glfwGetTime();
        
        if (current_time - g->last_tick > 0.01)
        {
            glClearColor(g->background[0], g->background[1], g->background[2], 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            if (g->game_world)
            {
                if (g->game_world->update)
                    g->game_world->update(g->game_world);
                render_game_world(g->game_world, g->camera);
            }
            g->last_tick = current_time;
            glfwSwapBuffers(g->game_window);
        }
        
        glfwPollEvents();
    }
}

void destroy_game(game_t *g)
{
    if (g->game_world)
    destroy_game_world(g->game_world);
    destroy_camera(g->camera);
    glfwDestroyWindow(g->game_window);
    glfwTerminate();
}

void on_resize(GLFWwindow *win, int width, int height)
{
    glViewport(0, 0, width, height);
}