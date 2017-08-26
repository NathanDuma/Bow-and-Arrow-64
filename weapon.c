/* 
 * File:   weapon.h
 * Author: Nathan Duma
 *
 */

#include "weapon.h"


static void playNextAnimation(weapon *self, display_context_t *disp){
    self->ana->state = (int)(self->ana->state + 1) % self->ana->size;
    graphics_draw_sprite_trans(*disp, self->v->x, 
                               self->v->y, self->ana[(int)self->ana->state].a);
}

static void destructWeapon(weapon *self){
    free(self->v);
    free(self);
}

weapon *initWeapon(char type){
    weapon *self = malloc(sizeof(weapon));
    
    self->type = type; // a for arrow, add more later maybe?
    
    self->v = malloc(sizeof(vector));
    self->v->x = 0.0;
    self->v->y = 0.0;
    
    if (self->type == 'a'){
        // there are 1 animation for the arrow
        int size = 1;
        self->ana = malloc(size * sizeof(animation));
        // initialize alive animation
        self->ana->size = size;
        self->ana->state = 0;

        int fp = 0;
        fp = dfs_open("/arrow.sprite");
        self->ana[0].a = malloc(dfs_size(fp));
        dfs_read(self->ana[0].a, 1, dfs_size(fp), fp);
        dfs_close(fp);
    }

    
    self->destructWeapon = destructWeapon;
    self->playNextAnimation = playNextAnimation;
    
    return self;
}
