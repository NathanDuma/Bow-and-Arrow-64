/* 
 * File:   enemy.h
 * Author: Nathan Duma
 *
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <ultra64.h>
#include <malloc.h>
#include "vector.h"
#include "common.h"
#include "hero.h"
#include "bool.h"
#include "weapon.h"


typedef enum {
    redBalloon, yellowBalloon, butterfly, 
    fire, slime, vulture, wind, scroll,
    bullseye, dove, tree, flame, watcher,
    fairy, flashm
} enemyType;

typedef struct enemy{
    enemyType type; // type of enemy
    int deadCounter; // how long to animate dead animation before it goes off screen
    int draw; // how often to alternate the animation
    int weaponCount; // how many weapons the enemy has
    bool hit; // indicates whether or not the enemy has been hit
    bool offScreen; // indicates if the enemy is off screen
    bool hostile; // if the enemy is hostile
    vector2D v; // position of enemy
    vector2D scale; // scale of enemy
    weapon *w; // the tree and watcher has weapons
    animation alive; // alive animation for enemy
    animation dead; // dead animation
    
    void (*drawEnemy)(struct enemy *self, Gfx **glistp);
    void (*move)(struct enemy *self);
    void (*checkCollisonWithHero)(struct enemy *self, struct hero *h);
    void (*checkCollisonWithWeapon)(struct enemy *self, struct weapon *w);
    void (*destructEnemy)(struct enemy *self);
} enemy;

void initEnemy(enemy *self, enemyType t, int enemyStartX, int enemyStartY);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* ENEMY_H */

