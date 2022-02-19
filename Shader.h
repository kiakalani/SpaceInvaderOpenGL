#ifndef _SHADER_H_
#define _SHADER_H_
#include <stdint.h>
#include <stdio.h>

typedef struct shader
{
    uint32_t shader_program;

}shader_t;

shader_t *new_shader(char*, char*);

void use_shader(shader_t*);

int32_t get_uniform_address(shader_t*, char*);

void stop_using_shader();

void destroy_shader(shader_t*);

char *read_file(char*);

#endif