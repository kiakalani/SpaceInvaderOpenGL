#ifndef _SHADER_H_
#define _SHADER_H_
#include <stdint.h>
#include <stdio.h>
/**
 * @brief A shader program to be used for rendering
 * 
 */
typedef struct shader
{
    uint32_t shader_program;

}shader_t;

/**
 * @brief Creates a shader from the given two file paths
 * 
 * @return shader_t* 
 */
shader_t *new_shader(char*, char*);

/**
 * @brief Uses the shader for rendering
 * 
 */
void use_shader(shader_t*);

/**
 * @brief Get the uniform address object by its name
 * 
 * @return int32_t 
 */
int32_t get_uniform_address(shader_t*, char*);

/**
 * @brief Unbinds any shaders that were selected
 * 
 */
void stop_using_shader();

/**
 * @brief Deallocates the shader
 * 
 */
void destroy_shader(shader_t*);

/**
 * @brief Helper function to read a file.
 * 
 * @return char* 
 */
char *read_file(char*);

#endif