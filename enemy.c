/* 
 * File:   enemy.c
 * Author: Nathan Duma
 *
 */


#include "enemy.h"


static void playNextAnimation(enemy *self, display_context_t *disp){
    animation *playNext;
    // get animation to play
    if (!self->hit){
        playNext = self->alive;
    } else{
        playNext = self->dead;
    }
    
    playNext->state = (int)(playNext->state + 1) % playNext->size;
    graphics_draw_sprite_trans(*disp, self->v->x, 
                               self->v->y, playNext->a[(int)playNext->state]);
    
    // move the object
    self->move(self);
    
    playNext = NULL;
    free(playNext);
}


static void move(enemy *self){
    if (!self->hit){ // alive animations
        if (self->type == redBalloon || self->type == yellowBalloon){
            float inc = 5.0;
            self->v->y = (int)(self->v->y - inc + SCREENHEIGHT) % SCREENHEIGHT;
        }
    } else{ // dead animations
        if (self->type == redBalloon || self->type == yellowBalloon){
            float inc = 5.0;
            self->v->y += inc;
        }
    }
}

static void initLocation(enemy *self, float x, float y){
    self->v->x = x;
    self->v->y = y;
}

static bool checkBoundingBox(vector *topLeft, vector *bottomRight, weapon *w){
    float inwardFactor = 0.75;
    // the 25% of the end of the weapon can damage the enemy
    vector weaponTopLeft = {(w->v->x + inwardFactor * (w->ana->a[0]->width)),
                            w->v->y};
    vector weaponBottomRight = {w->v->x + w->ana->a[0]->width,
                                w->v->y + w->ana->a[0]->height};
    
    // check if the weapon collides with the enemy
    return !((weaponTopLeft.x > bottomRight->x) || (weaponBottomRight.x < topLeft->x) ||
             (weaponTopLeft.y > bottomRight->y) || (weaponBottomRight.y < topLeft->y));
}


static void checkCollison(enemy *self, weapon *w){
    // get the bounding box and see if it collides with the weapon
    if (self->type == redBalloon || self->type == yellowBalloon){
        // width and height of hitbox
        float width = (float)self->alive->a[0]->width;
        float height = 26.0;
        // bounding box, top left of the sprite is the coordinates of enemy
        vector bottomRight = {self->v->x + width, self->v->y + height};
        if (checkBoundingBox(self->v, &bottomRight, w)){
            self->hit = true;
        } 
    }
}


static void destructEnemy(enemy *self){
    free(self->v);
    self->alive->destructAnimation(self->alive);
    self->dead->destructAnimation(self->dead);
    free(self->alive);
    free(self->dead);
}


enemy *initEnemy(enum enemies e){
    enemy *self = malloc(sizeof(enemy));
    
    self->v = malloc(sizeof(vector));
    self->v->x = 0.0;
    self->v->y = 0.0;

    self->type = e;
    self->hit = false;
    
    self->checkCollison = checkCollison;
    self->move = move;
    self->initLocation = initLocation;
    self->destructEnemy = destructEnemy;
    self->playNextAnimation = playNextAnimation;
    
    self->alive = initAnimation();
    self->dead = initAnimation();
    
    if (e == redBalloon){
        const char *redBalloonAlive[] = {"/balloon.sprite"};
        const char *redBalloonDead[] = {"/balloon_dead.sprite"};
        int aliveSize = 1;
        int deadSize = 1;
        
        self->alive->addAnimations(self->alive, redBalloonAlive, aliveSize);
        self->dead->addAnimations(self->dead, redBalloonDead, deadSize);
    }
    
    return self;
}