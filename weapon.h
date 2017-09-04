/* 
 * File:   weapon.h
 * Author: Nathan Duma
 *
 */

#ifndef WEAPON_H
#define WEAPON_H

#include "vector.h"
#include "animation.h"
#include <malloc.h>
#include <stdbool.h>

enum weapons{
    arrows
};

typedef struct weapon{
    enum weapons type; // type of weapon
    bool shot; // indicates if the weapon has been already soht
    bool offScreen; // indicates if the weapon is off screen
    vector *v; // position of enemy
    animation *ana; // animation for the weapon
    
    void (*playNextAnimation)(struct weapon *self, display_context_t *disp);
    void (*shoot)(struct weapon *self);
    void (*destructWeapon)(struct weapon *self);
} weapon;


weapon *initWeapon(enum weapons w);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* WEAPON_H */

