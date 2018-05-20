/* 
 * File:   weapon.h
 * Author: Nathan Duma
 *
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <ultra64.h>
#include <nusys.h>
#include <malloc.h>
#include "vector.h"
#include "animation.h"
#include "bool.h"
#include "common_sprites.h"

typedef enum {
    arrows, thunder, apples, firearrow
} weaponType;

typedef struct weapon {
    weaponType type; // type of weapon
    bool shot; // indicates if the weapon has been already shot
    bool offScreen; // indicates if the weapon is off screen
    float speed;
    vector2D v; // position of enemy
    vector2D scale;
    animation a; // animation of the weapon

    void (*drawWeapon)(struct weapon *self, Gfx **glistp);
    void (*updatePosition)(struct weapon *self);
    void (*checkCollisonWithWeapon)(struct weapon *w1, struct weapon *w2);
    void (*shoot)(struct weapon *self);
    void (*destructWeapon)(struct weapon *self);
} weapon;


void initWeapon(weapon *self, weaponType w);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* WEAPON_H */

