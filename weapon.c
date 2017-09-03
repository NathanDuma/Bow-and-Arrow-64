/* 
 * File:   weapon.h
 * Author: Nathan Duma
 *
 */

#include "weapon.h"


static bool checkOffScreen(float *x, float *y){
    return (*x > SCREENWIDTH || *x < 0) ||
           (*y > SCREENHEIGHT || *y < 0); 
}


static void playNextAnimation(weapon *self, display_context_t *disp){
    if (self->shot && !self->offScreen){
        self->ana->state = (int)(self->ana->state + 1) % self->ana->size;
        graphics_draw_sprite_trans(*disp, self->v->x, 
                                   self->v->y, self->ana->a[(int)self->ana->state]);
        // update position of the weapon
        self->v->x += self->v->speed;
        // stop drawing the weapon if it go off screen
        if (checkOffScreen(&self->v->x, &self->v->y)){
            self->offScreen = true;
            self->v->x = -200;
            self->v->y = -200;
        }
    }

}

static void shoot(weapon *self){
    // we need to fix the position of the weapon to be in front of hero when shot
    float weaponBaseX = 0.0;
    float weaponBaseY = 0.0;
    
    self->shot = true;
    self->offScreen = false;
    self->v->speed = 0.0;
    
    if (self->type == arrows){
        weaponBaseX = 45.0;
        weaponBaseY = 40.0;
        self->v->speed = 15.0;
    }
        // set position of weapon
    self->v->x = self->v->x + weaponBaseX;
    self->v->y = self->v->y + weaponBaseY;
}


static void destructWeapon(weapon *self){
    self->ana->destructAnimation(self->ana);
    free(self->ana);
    
    free(self->v);
}

weapon *initWeapon(enum weapons w){
    weapon *self = malloc(sizeof(weapon));
    
    self->type = w; // a for arrow, add more later maybe?
    self->shot = false;
    self->offScreen = true;
    
    self->v = malloc(sizeof(vector));
    self->v->x = 0.0;
    self->v->y = 0.0;
    
    if (self->type == arrows){
        // there are 1 animation for the arrow
        int size = 1;
        const char *arrowSprite[] = {"/arrow.sprite"};
        
        self->ana = initAnimation(size);
        self->ana->addAnimations(self->ana, arrowSprite, size);
        
        // little icon is needed too
/*
        size = 1;
        const char *littleArrowSprite[] = {"/arrow_icon.sprite"};
        
        self->anaIcon = initAnimation(size);
        self->ana->addAnimations(self->ana, littleArrowSprite, size);
*/
    }

    
    self->destructWeapon = destructWeapon;
    self->shoot = shoot;
    self->playNextAnimation = playNextAnimation;
    
    return self;
}
