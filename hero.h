/* 
 * File:   hero.h
 * Author: Nathan Duma
 *
 */

#ifndef HERO_H
#define HERO_H

#include "debug.h"
#include "vector.h"
#include "weapon.h"
#include "animation.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

enum heros{
    normal
};

typedef struct hero{
    enum heros type; // type of hero
    bool hit; // whether the hero has been hit by an enemy or not
    int quiverCount; // amount of quivers left
    vector *v; // position of hero
    weapon **w; // the weapons the hero has
    animation *alive; // alive animation of hero
    animation *dead; // dead animation of hero
    
    void (*playNextAnimation)(struct hero *self, display_context_t *disp, bool pressed);
    void (*move)(struct hero *self, enum direction d);
    void (*destructHero)(struct hero *self, int quiverMax);
} hero;

hero *initHero(enum heros h, int quiverMax);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HERO_H */

