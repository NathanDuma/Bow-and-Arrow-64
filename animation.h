/* 
 * File:   animation.h
 * Author: Nathan Duma
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <libdragon.h>
#include <malloc.h>

typedef struct animation{
    sprite_t **a;
    int size;
    char state;
    
    void (*addAnimations)(struct animation *self, const char *sprites[], int size);
    void (*destructAnimation)(struct animation *self);
} animation;

animation *initAnimation();

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* ANIMATION_H */

