/* 
 * File:   enemy.h
 * Author: Nathan Duma
 *
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <malloc.h>
#include "vector.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Enemy types:
 * 
 * 
 * 
 */

typedef struct enemy{
    char type;
    bool hit;
    vector *v;
    animation *alive;
    animation *dead;
    
    void (*playNextAnimation)(struct enemy *self, display_context_t *disp);
    void (*move)(struct enemy *self);
    void (*checkCollison)(struct enemy *self);
    void (*destructEnemy)(struct enemy *self);
} enemy;

//extern enemy *initEnemy();

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* ENEMY_H */

