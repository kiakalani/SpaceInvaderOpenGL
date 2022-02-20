#include "Camera.h"
#include <stdlib.h>
#include <string.h>

camera_t *new_camera()
{
    camera_t *cam = (camera_t*)malloc(sizeof(camera_t));
    memset(cam->position, 0, sizeof(float) * 2);
    cam->scale = 0.1f;
    return cam;
}


float *create_camera_mat4(camera_t *cam)
{
    float *camera_mat = (float*)calloc(sizeof(float), 16);
    camera_mat[0] = cam->scale;
    camera_mat[5] = cam->scale;
    camera_mat[10] = cam->scale;
    camera_mat[15] = 1.0f;
    return camera_mat;
}

void destroy_camera(camera_t *cam)
{
    free(cam);
}