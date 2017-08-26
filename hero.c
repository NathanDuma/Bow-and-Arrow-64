/* 
 * File:   hero.c
 * Author: Nathan Duma
 *
 */

#include "hero.h"


// play the next animation
static void playNextAnimation(hero *self, display_context_t *disp, bool pressed){
    animation *playNext;
    // get correct animation to play when hit or not
    if (!self->hit){
        playNext = self->alive;
    } else{
        playNext = self->dead;
    }
    
    if (playNext != NULL){
        // only change animation when pressed
        if (pressed) playNext->state = (int)(playNext->state + 1) % playNext->size;
        graphics_draw_sprite_trans(*disp, self->v->x, 
                                   self->v->y, playNext[(int)playNext->state].a);
    }

    playNext = NULL;
    free(playNext);
}


// move the character up and down by 5 units
static void move(hero *self, char dir){
    float inc = 5.0;
    if (dir == 'u'){
        self->v->y -= inc;
    } else{
        self->v->y += inc;
    }
}


// destructor for hero struct
static void destructHero(hero *self){
    // free alive animation
    free(&self->alive->a);

    // free dead animation
    free(&self->dead->a);
    
    // free vector
    free(self->v);
    free(self);
}



hero *initHero(){
    hero *self = malloc(sizeof(hero));
    // initialize type
    self->type = 'h';
     // initialize hit
    self->hit = false;
    // initialize  vector
    self->v = malloc(sizeof(vector));
    self->v->x = 50.0;
    self->v->y = 50.0;
    
    // there are 3 animations for the hero
    int size = 3;
    self->alive = malloc(size * sizeof(animation));
    // initialize alive animation
    self->alive->size = size;
    self->alive->state = 0;
    
    int fp = 0;
    fp = dfs_open("/hero_without_arrow.sprite");
    self->alive[0].a = malloc(dfs_size(fp));
    dfs_read(self->alive[0].a, 1, dfs_size(fp), fp);
    dfs_close(fp);
    
    fp = dfs_open("/hero_stand.sprite");
    self->alive[1].a = malloc(dfs_size(fp));
    dfs_read(self->alive[1].a, 1, dfs_size(fp), fp);
    dfs_close(fp);
    
    fp = dfs_open("/hero_armed.sprite");
    self->alive[2].a = malloc(dfs_size(fp));
    dfs_read(self->alive[2].a, 1, dfs_size(fp), fp);
    dfs_close(fp);
    
    // initialize dead animation
    self->dead = malloc(sizeof(animation));
    self->dead->size = 3;
    self->dead->state = 0;
    self->dead->a = malloc(sizeof(animation) * self->dead->size);
    // initialize hero functions
    self->destructHero = destructHero;
    self->move = move;
    self->playNextAnimation = playNextAnimation;
    
    return self;
}
