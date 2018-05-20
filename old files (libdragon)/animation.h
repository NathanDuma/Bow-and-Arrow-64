/* 
 * File:   animation.h
 * Author: Nathan Duma
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include "debug.h"
#include <libdragon.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct animation{
    sprite_t **a; // array of sprites, access using a[state]
    int size; // the max amount of animations
    char state; // the current state of the animation
    
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

