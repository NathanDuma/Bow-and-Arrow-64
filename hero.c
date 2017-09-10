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
        // if the arrow went from shooting to neutral, fire the weapon
        if (pressed && (playNext->state == 0) && (self->quiverCount > 0)){
            self->w[self->quiverCount-1]->v->x = self->v->x;
            self->w[self->quiverCount-1]->v->y = self->v->y;
            self->w[self->quiverCount-1]->shoot(self->w[self->quiverCount-1]);
            
            self->quiverCount--;
        }
    }

    playNext = NULL;
    free(playNext);
}


// move the character up and down by inc units
static void move(hero *self, enum direction d){
    float inc = 10.0;
    if (d == up){
        self->v->y -= inc;
    } else{
        self->v->y += inc;
    }
    
    int heroMoveBoundary = 50;
    // we need to let the hero not go out of screen bounds
    if (self->v->y < -heroMoveBoundary){
        self->v->y = -heroMoveBoundary;
    } else if (self->v->y > (SCREENHEIGHT - heroMoveBoundary)){
        self->v->y = SCREENHEIGHT - heroMoveBoundary;
    }
}


// destructor for hero struct
// caller frees self
static void destructHero(hero *self, int quiverMax){
    // free animations
    self->alive->destructAnimation(self->alive);
    self->dead->destructAnimation(self->dead);
    free(self->alive);
    free(self->dead);
    
    // free vector
    free(self->v);
    
    // free weapons
    for (int i = 0; i < quiverMax; i++){
        self->w[i]->destructWeapon(self->w[i]);
        free(self->w[i]);
    }
    free(self->w);
}



hero *initHero(enum heros h, int quiverMax){
    hero *self = malloc(sizeof(hero));
    // initialize type
    self->type = h;
     // initialize hit
    self->hit = false;
    // initialize  vector
    self->v = malloc(sizeof(vector));
    
    if (h == normal){
        // there are 3 animations for the normal hero
        int size = 4;
        self->alive = initAnimation();

        const char *heroAliveSprite[] = {"/hero_without_arrow.sprite",
        "/hero_stand.sprite", "/hero_almost_armed.sprite", "/hero_armed.sprite"};

        self->alive->addAnimations(self->alive, heroAliveSprite, size);

        // initialize dead animation
        self->dead = initAnimation();

        const char *heroDeadSprite[] = {"/hero_dead.sprite"};

        self->dead->addAnimations(self->dead, heroDeadSprite, size);

        // initialize the weapons
        self->quiverCount = quiverMax;
        self->w = malloc(sizeof(weapon*) * self->quiverCount);
        for (int i = 0; i < self->quiverCount; i++){
            self->w[i] = initWeapon(arrows);
        }
    }

    
    // initialize hero functions
    self->destructHero = destructHero;
    self->move = move;
    self->playNextAnimation = playNextAnimation;
    
    self->v->x = 0.0;
    self->v->y = rand() % SCREENHEIGHT;
    
    return self;
}
