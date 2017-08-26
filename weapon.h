/* 
 * File:   weapon.h
 * Author: Nathan Duma
 *
 */

#ifndef WEAPON_H
#define WEAPON_H

#include "vector.h"
#include <malloc.h>


typedef struct weapon{
    char type;
    vector *v;
    animation *ana;
    
    void (*playNextAnimation)(struct weapon *self, display_context_t *disp);
    void (*destructWeapon)(struct weapon *self);
} weapon;


weapon *initWeapon(char type);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* WEAPON_H */

