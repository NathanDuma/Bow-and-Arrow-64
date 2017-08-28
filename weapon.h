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
    enum weapons type;
    bool shot;
    vector *v;
    animation *ana;
    
    void (*playNextAnimation)(struct weapon *self, display_context_t *disp);
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

