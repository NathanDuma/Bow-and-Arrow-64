/* 
 * File:   weapon.h
 * Author: Nathan Duma
 *
 */

#include "weapon.h"


static void playNextAnimation(weapon *self, display_context_t *disp){
    if (self->shot){
        float inc = 10.0;
        self->ana->state = (int)(self->ana->state + 1) % self->ana->size;
        graphics_draw_sprite_trans(*disp, self->v->x, 
                                   self->v->y, self->ana->a[(int)self->ana->state]);
        // update position of the weapon
        self->v->x += inc;
        // stop drawing the weapon if it go off screen
        if (self->v->x >= (SCREENWIDTH + self->ana->a[0]->width)){
            self->shot = false;
        }
    }

}

static void destructWeapon(weapon *self){
    free(self->v);
    self->ana->destructAnimation(self->ana);
    free(self);
}

weapon *initWeapon(enum weapons w){
    weapon *self = malloc(sizeof(weapon));
    
    self->type = w; // a for arrow, add more later maybe?
    self->shot = false;
    
    self->v = malloc(sizeof(vector));
    self->v->x = 0.0;
    self->v->y = 0.0;
    
    if (self->type == arrows){
        // there are 1 animation for the arrow
        int size = 1;
        const char *arrowSprite[] = {"/arrow.sprite"};
        
        self->ana = initAnimation(size);
        self->ana->addAnimations(self->ana, arrowSprite, size);
    }

    
    self->destructWeapon = destructWeapon;
    self->playNextAnimation = playNextAnimation;
    
    return self;
}
