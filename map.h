/* 
 * File:   map.h
 * Author: Nathan Duma
 *
 */

#ifndef MAP_H
#define MAP_H

#include "hero.h"
#include "enemy.h"
#include "animation.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct map{
    display_context_t disp;
    int mapNumber;
    int quiverMax;
    hero *h;
    enemy **e;
    int enemyCount;
    
    void (*switchMap)(struct map *self, int mapNumber);
    void (*render)(struct map *self);
    void (*destructMap)(struct map *self);
} map;

map *initMap(int mapNumber);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MAP_H */

