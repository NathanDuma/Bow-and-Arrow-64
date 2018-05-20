/* 
 * File:   enemy.h
 * Author: Nathan Duma
 *
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "debug.h"
#include "vector.h"
#include "animation.h"
#include "hero.h"
#include "weapon.h"
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum enemies{
    redBalloon, yellowBalloon, butterfly, 
    fire, slime, vulture, wind, scroll,
    bullseye, dove, tree, flame, watcher,
    fairy, flashm1, flashm2, flashm3
};

typedef struct enemy{
    enum enemies type; // type of enemy
    bool hit; // indicates whether or not the enemy has been hit
    bool offScreen; // indicates if the enemy is off screen
    vector *v; // position of enemy
    animation *alive; // alive animation
    animation *dead; // dead animation
    
    void (*playNextAnimation)(struct enemy *self, display_context_t *disp);
    void (*move)(struct enemy *self);
    void (*initLocation)(struct enemy *self, float x, float y);
    void (*checkCollison)(struct enemy *self, weapon *w, hero *h);
    void (*destructEnemy)(struct enemy *self);
} enemy;

enemy *initEnemy(enum enemies e);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* ENEMY_H */

