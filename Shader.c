#include "Shader.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

char *read_file(char *path)
{
    FILE *f = fopen(path, "r");
    if (!f) return (char*)0; // Error finding file

    char comp = '\0';
    uint32_t arr_size, arr_n;
    char *arr = (char*)malloc(sizeof(char) * (arr_size = 2));
    arr[arr_n = 0] = '\0';
    while ((comp = fgetc(f)) != EOF)
    {
        if (arr_size <= arr_n + 1) arr = (char*)realloc(arr, sizeof(char) * (arr_size *= 2));
        arr[arr_n++] = comp;
        arr[arr_n] = '\0';
    }
    return (char*)realloc(arr, sizeof(char) * (arr_n + 1));
}

shader_t *new_shader(char *vertex, char *fragment)
{
    // Reading vertex and fragment shaders
    char *vertex_shader = read_file(vertex);
    if (!vertex_shader) return (shader_t*)(uint64_t)(printf("Error reading vertex shader \"%s\"!\n", vertex) && 0);
    char *fragment_shader = read_file(fragment);
    if (!fragment_shader) return (shader_t*)(uint64_t)(printf("Error reading fragment shader shader \"%s\"!\n", fragment) && 0);

    // Variables to check status of compilation of the shaders
    uint32_t size_message = 500;
    char *shader_compile_message = (char*) malloc(sizeof(char) * size_message);
    int success = 0;

    // Compiling the vertex shader
    uint32_t vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, (const char**)(&vertex_shader), (int*)0);
    glCompileShader(vert);
    

    glGetShaderiv(vert, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vert, size_message, (int*)0, shader_compile_message);
        printf("Error compiling vertex shader:\n%s\n", shader_compile_message);
    }

    // Compiling the fragment shader

    uint32_t frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, (const char**)(&fragment_shader), (int*)0);
    glCompileShader(frag);

    glGetShaderiv(frag, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(frag, size_message, (int*)0, shader_compile_message);
        printf("Error compiling fragment shader:\n%s\n", shader_compile_message);
    }

    // Creating the shader and linking them
    shader_t *shader = (shader_t*)malloc(sizeof(shader_t));

    shader->shader_program = glCreateProgram();

    glAttachShader(shader->shader_program, vert);
    glAttachShader(shader->shader_program, frag);
    glLinkProgram(shader->shader_program);
    
    glGetProgramiv(shader->shader_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader->shader_program, size_message, (int*)0, shader_compile_message);
        printf("Error linking the shaders:\n%s\n", shader_compile_message);
    }

    // Deallocation of unneccessary instances
    glDeleteShader(vert);
    glDeleteShader(frag);
    free(vertex_shader);
    free(fragment_shader);
    free(shader_compile_message);

    int32_t att_location = glGetAttribLocation(shader->shader_program, "vertex");
    glVertexAttribPointer(att_location, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(att_location);

    att_location = 0;

    att_location = glGetAttribLocation(shader->shader_program, "uv");
    glVertexAttribPointer(att_location, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(sizeof(float) * 2));
    glEnableVertexAttribArray(att_location);

    return shader;

}

void use_shader(shader_t *s)
{
    glUseProgram(s->shader_program);
}

int32_t get_uniform_address(shader_t *s, char *name)
{
    return glGetUniformLocation(s->shader_program, name);
}

void stop_using_shader()
{
    glUseProgram(0);
}

void destroy_shader(shader_t *s)
{
    glDeleteProgram(s->shader_program);
    free(s);
}