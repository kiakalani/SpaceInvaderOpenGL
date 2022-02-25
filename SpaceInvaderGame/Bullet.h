#ifndef _BULLET_H_
#define _BULLET_H_
#include "../GameObject.h"

typedef struct bullet_components
{
    float creation_time;
    float longevity;
    game_object_t *owner;
    
}bullet_components_t;

game_object_t *new_bullet(game_object_t*, float);
void destroy_bullet(game_object_t*);
void bullet_update(game_object_t*);
#endif