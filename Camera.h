#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "Shader.h"

/**
 * @author Kia Kalani
 * <code>struct camera</code> is a structure that contains
 * the definition of a 2D camera for the objects to be rendered
 * in.
 */
typedef struct camera
{
    float position[2]; /* The 2D position of the camera*/
    float scale; /* The 2D cube size for camera */
}camera_t;

/**
 * @brief Dynamically allocates a 4x4 matrix with the camera transformation
 * applied.
 * 
 * @return float*: The 4x4 matrix of camera 
 */
float *create_camera_mat4(camera_t*);

/**
 * @brief Creates a new camera instance
 * 
 * @return camera_t* 
 */
camera_t *new_camera();

/**
 * @brief Destroys the camera's instance
 * @param camera_t*: the camera to destroy
 * 
 */
void destroy_camera(camera_t*);

#endif