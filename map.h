/* 
 * File:   map.h
 * Author: Nathan Duma
 *
 */

#ifndef MAP_H
#define MAP_H

#include <ultra64.h>
#include "hero.h"
#include "enemy.h"
#include "cont.h"
#include "common_sprites.h"
#include "bool.h"
#include "game_state.h"

typedef struct map {
    bool paused;
    int mapNumber; // current map number
    int quiverMax; // maximum amount of quivers for the map
    int enemyCount; // the amount of enemies on the map
    hero h; // the current hero character
    enemy *e; // enemies

    void (*drawMap)(struct map *self, Gfx **glistp);
    void (*updateMap)(struct map *self);
    void (*reinitMap)(struct map *self);
    void (*destructMap)(struct map *self);
} map;

void initMap(map *self);

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif /* MAP_H */

