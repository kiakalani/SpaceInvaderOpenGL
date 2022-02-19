#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>

#include "Texture.h"


texture_t *new_texture(char *path)
{
    texture_t *t = (texture_t*)malloc(sizeof(texture_t));
    t->texture = SOIL_load_OGL_texture(path, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);
    if (!t->texture)
    {
        free(t);
        return (texture_t*)(printf("Error loading texture \"%s\"\n", path) && 0);
    }
}

void destroy_texture(texture_t *t)
{
    glDeleteTextures(1, &(t->texture));
    free(t);
}

void use_texture(texture_t *t, shader_t *s)
{
    int32_t texpath = get_uniform_address(s, "texture");
    glUniform1i(texpath, t->texture);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, t->texture);

    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T , GL_REPEAT);
}


void stop_using_texture()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

