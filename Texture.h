#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include <stdint.h>
#include "Shader.h"
/**
 * @brief texture type for loading textures from
 * outside of the code.
 * 
 */
typedef struct texture
{
    uint32_t texture;
}texture_t;

/**
 * @brief Creates a new texture from a given file path which is an image.
 * 
 * @return texture_t* 
 */
texture_t *new_texture(char*);

/**
 * @brief Deallocates the texture
 * 
 */
void destroy_texture(texture_t*);

/**
 * @brief Using the texture to be sent to the shader.
 * 
 */
void use_texture(texture_t*, shader_t*);
/**
 * @brief Unbinds the texture
 * 
 */
void stop_using_texture();

#endif