/* 
 * File:   enemy.h
 * Author: Nathan Duma
 *
 */

#ifndef ENEMY_H
#define ENEMY_H


#include "vector.h"
#include "animation.h"
#include "weapon.h"
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum enemies{
    redBalloon, yellowBalloon, bird,
    butterfly, fire, slime, vulture, wind
};

typedef struct enemy{
    enum enemies type;
    bool hit;
    vector *v;
    animation *alive;
    animation *dead;
    
    void (*playNextAnimation)(struct enemy *self, display_context_t *disp);
    void (*move)(struct enemy *self);
    void (*initLocation)(struct enemy *self, float x, float y);
    void (*checkCollison)(struct enemy *self, weapon *w);
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

