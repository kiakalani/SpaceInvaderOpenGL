#include "Shape.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

shape_t *new_quad_shape()
{
    shape_t *s = (shape_t*)calloc(sizeof(shape_t), 1);
    glGenBuffers(1, &(s->vertex_buffer));
    glGenBuffers(1, &(s->element_buffer));
    
    float vertex[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 1.0f, 1.0f
    };

    uint32_t faces[] = {0, 1, 2, 1, 2, 3};

    s->size = sizeof(faces) / sizeof(uint32_t);
    glBindBuffer(GL_ARRAY_BUFFER, s->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faces), faces, GL_STATIC_DRAW);

    return s;
}

void use_shape(shape_t *shape, shader_t *shader)
{
    glBindBuffer(GL_ARRAY_BUFFER, shape->vertex_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shape->element_buffer);
    
}

void destroy_shape(shape_t *s)
{
    glDeleteBuffers(1, &(s->element_buffer));
    glDeleteBuffers(1, &(s->vertex_buffer));
    free(s);
}
