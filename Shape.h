#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <stdint.h>
#include "Shader.h"

/**
 * @brief <code>shape_t</code> contains the vertex and
 * element buffer for a shape to be used for rendering.
 * 
 */
typedef struct shape
{
    uint32_t size;
    uint32_t vertex_buffer, element_buffer;
}shape_t;

/**
 * @brief Creates a new quad shape
 * 
 * @return shape_t* 
 */
shape_t *new_quad_shape();

/**
 * @brief Uses the shape for a given shader
 * 
 */
void use_shape(shape_t*);

/**
 * @brief Deallocates the shape
 * 
 */
void destroy_shape(shape_t*);

#endif