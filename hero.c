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
    // draw the player
    if (playNext != NULL){
        // only change animation when pressed
        if (pressed && (self->quiverCount > 0)) playNext->state = (int)(playNext->state + 1) % playNext->size;
        graphics_draw_sprite_trans(*disp, self->v->x, 
                                   self->v->y, playNext->a[(int)playNext->state]);
    
        if (pressed && (playNext->state == 0) && (self->quiverCount > 0)){
            // we need to fix the position of the arrows to be in front of hero
            float arrowBaseX = 45.0;
            float arrowBaseY = 40.0;
            self->w[self->quiverCount-1]->shot = true;
            // set position of weapon
            self->w[self->quiverCount-1]->v->x = self->v->x + arrowBaseX;
            self->w[self->quiverCount-1]->v->y = self->v->y + arrowBaseY;
            
            self->quiverCount--;
        }
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
static void destructHero(hero *self, int quiverMax){
    // free alive animation
    for (int i = 0; i < self->alive->size; i++){
        free(self->alive[i].a);
    }
    free(self->alive);
    

    // free dead animation
    for (int i = 0; i < self->dead->size; i++){
        free(self->dead[i].a);
    }
    free(self->dead);
    
    // free weapons
    for (int i = 0; i < quiverMax; i++){
        self->w[i]->destructWeapon(self->w[i]);
    }
    
    
    // free vector
    free(self->v);
}



hero *initHero(enum heros h, int quiverMax){
    hero *self = malloc(sizeof(hero));
    // initialize type
    self->type = h;
     // initialize hit
    self->hit = false;
    // initialize  vector
    self->v = malloc(sizeof(vector));
    
    // there are 3 animations for the hero
    int size = 3;
    self->alive = initAnimation();
    
    const char *heroSprite[] = {"/hero_without_arrow.sprite",
    "/hero_stand.sprite", "/hero_armed.sprite"};
    
    self->alive->addAnimations(self->alive, heroSprite, size);
    
    self->quiverCount = quiverMax;
    self->w = malloc(sizeof(weapon*) * self->quiverCount);
    for (int i = 0; i < self->quiverCount; i++){
        self->w[i] = initWeapon(arrows);
    }
    
    // initialize dead animation
    self->dead = malloc(sizeof(animation));
    self->dead->size = 3;
    self->dead->state = 0;
    self->dead->a = malloc(sizeof(animation) * self->dead->size);
    // initialize hero functions
    self->destructHero = destructHero;
    self->move = move;
    self->playNextAnimation = playNextAnimation;
    
    self->v->x = 0.0;
    self->v->y = SCREENHEIGHT/2;
    
    return self;
}
