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
#include <stdbool.h>

bool paused; // used to pause the game

typedef struct map{
    display_context_t *disp; // render graphics to screen using the display
    int mapNumber; // current map number
    int quiverMax; // maximum amount of quivers for the map
    hero *h; // the current hero character
    enemy **e; // array of enemies on the map
    int enemyCount; // the amount of enemies on the map
    
    int (*render)(struct map *self);
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

