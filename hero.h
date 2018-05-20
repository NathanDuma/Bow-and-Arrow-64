/* 
 * File:   hero.h
 * Author: Nathan Duma
 *
 */

#ifndef HERO_H
#define HERO_H

#include <ultra64.h>
#include <malloc.h>
#include "animation.h"
#include "vector.h"
#include "bool.h"
#include "weapon.h"
//#include "Texture/common_sprites.h"


typedef enum {
    normal
} heroType;

typedef struct hero {
    heroType type; // type of hero
    bool hit; // whether the hero has been hit by an enemy or not
    bool hidden; // don't draw on scroll maps
    int quiverCount; // amount of quivers left
    int quiverMax; // need this for freeing 
    vector2D v; // position of hero
    vector2D scale; // scale of the hero
    animation alive; // alive animation
    animation dead; // dead animation
    weapon *w; // the weapons the hero has

    void (*drawHero)(struct hero *self, Gfx **glistp);
    void (*move)(struct hero *self, direction d);
    void (*checkCollisonWithWeapon)(struct hero *self, struct weapon *w);
    void (*destructHero)(struct hero *self);
} hero;

void initHero(hero *self, heroType h, int quiverMax);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HERO_H */

