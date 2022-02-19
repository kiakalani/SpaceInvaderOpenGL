#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <stdint.h>
#include "Shader.h"

typedef struct shape
{
    uint32_t size;
    uint32_t vertex_buffer, element_buffer;
}shape_t;

shape_t *new_quad_shape();

void use_shape(shape_t*, shader_t*);

void destroy_shape(shape_t*);

#endif