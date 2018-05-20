/* 
 * File:   animation.h
 * Author: Nathan Duma
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <ultra64.h>
#include <nusys.h>
#include <malloc.h>
#include "vector.h"
#include "game_state.h"
#include "font_ext.h"


typedef struct animation{
    Sprite **s; // array of sprites, access using a[state]
    Gfx *dsp;
    int size; // the max amount of animations
    int state; // the current state of the animation
    vector2D scale;
    
    void (*drawAnimation)(struct animation *self, Gfx **glistp, vector2D *v);
    void (*destructAnimation)(struct animation *self);
} animation;

void initAnimation(animation* self, Sprite **s, int size, vector2D *scale);
void initAnimation2(animation *self, Sprite **s, int size, vector2D *scale);
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* ANIMATION_H */

