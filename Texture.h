#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include <stdint.h>
#include "Shader.h"
typedef struct texture
{
    uint32_t texture;
}texture_t;

texture_t *new_texture(char*);
void destroy_texture(texture_t*);

void use_texture(texture_t*, shader_t*);
void stop_using_texture();

#endif