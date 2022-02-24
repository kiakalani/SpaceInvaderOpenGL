#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "Shader.h"
typedef struct camera
{
    float position[2];
    float scale;
}camera_t;

float *create_camera_mat4(camera_t*);

camera_t *new_camera();

void destroy_camera(camera_t*);

#endif