/* 
 * File:   enemy.c
 * Author: Nathan Duma
 *
 */


#include "enemy.h"

// check if two rectangles (hitboxes) collide
static bool checkBoundingBox(vector *topLeftR1, vector *bottomRightR1,
                             vector *topLeftR2, vector *bottomRightR2){
    return !((topLeftR1->x > bottomRightR2->x) || (bottomRightR1->x < topLeftR2->x) ||
             (topLeftR1->y > bottomRightR2->y) || (bottomRightR1->y < topLeftR2->y));
}

// check if the object is off screen
static bool checkOffScreen(float *x, float *y){
    return (*x > SCREENWIDTH || *x < 0) ||
           (*y > SCREENHEIGHT || *y < 0); 
}


static void playNextAnimation(enemy *self, display_context_t *disp){
    
    animation *playNext;
    // get animation to play
    if (!self->hit){
        playNext = self->alive;
    } else{
        if (checkOffScreen(&self->v->x, &self->v->y)){
            self->offScreen = true;
            self->move(self);
            return;
        }
        playNext = self->dead;
    }
    
    // get next state
    playNext->state = (int)(playNext->state + 1) % playNext->size;
    
    // move the object before it has been drawn
    if (!self->hit || (playNext->state == 0)) self->move(self);
    // draw the enemy
    graphics_draw_sprite_trans(*disp, self->v->x, 
                               self->v->y, playNext->a[(int)playNext->state]);
    
    playNext = NULL;
    free(playNext);
}

// move the specific enemy
// some enemies share the same movement types
static void move(enemy *self){
    if (!self->hit){ // alive animations
        if (self->type == redBalloon){
            float inc = 5.0;
            self->v->y = (int)(self->v->y - inc + SCREENHEIGHT) % SCREENHEIGHT;
        } else if (self->type == yellowBalloon){
            float inc = 9.0;
            self->v->y = (int)(self->v->y - inc + SCREENHEIGHT) % SCREENHEIGHT;
        } else if (self->type == butterfly || self->type == bullseye){
            float inc = 5.0;
            if (self->v->d == up){
                self->v->y -= inc;
            } else if (self->v->d == down){
                self->v->y += inc;
            }
            // check if the butterfly is out of bounds
            if (self->v->y > SCREENHEIGHT){
                self->v->d = up;
                self->v->y = SCREENHEIGHT;
            } else if (self->v->y < 0){
                self->v->d = down;
                self->v->y = 0;
            }
        } else if (self->type == slime || self->type == fire || 
                   self->type == vulture || self->type == wind){
            float inc = 5.0;
            self->v->x -= inc;
            if (self->v->x < 0){ // off screen
                self->hit = true;
            }
        }
    } else{ // dead animations
        if (self->type == redBalloon || self->type == yellowBalloon){
            float inc = 5.0;
            self->v->y += inc;
        } else if (self->type == butterfly){
            float inc = 5.0;
            self->v->x -= inc;
            self->v->y -= inc;
        } else if (self->type == slime || self->type == bullseye ||
                   self->type == fire || self->type == vulture ||
                   self->type == wind){
            self->v->x = -100;
            self->v->y = -100;
        }
    }
}


// init location of the enemy and direction
static void initLocation(enemy *self, float x, float y){
    self->v->x = x;
    self->v->y = y;

    self->v->d = up;
    self->offScreen = false;
}

// check collison between the enemy and (weapon or hero)
static void checkCollison(enemy *self, weapon *w, hero *h){
    // get the weapon hitbox
    float inwardFactor = 0.75;
    // the 25% of the end of the weapon can damage the enemy
    vector weaponTopLeft = {(w->v->x + inwardFactor * (w->ana->a[0]->width)),
                            w->v->y};
    vector weaponBottomRight = {w->v->x + w->ana->a[0]->width,
                                w->v->y + w->ana->a[0]->height};

    
    // get the bounding box and see if it collides with the weapon
    if (self->type == redBalloon || self->type == yellowBalloon){ 
        // width and height of hitbox
        float width = (float)self->alive->a[0]->width;
        float height = 26.0;
        // bounding box, top left of the sprite is the coordinates of enemy
        vector bottomRight = {self->v->x + width, self->v->y + height};
    
        if (checkBoundingBox(self->v, &bottomRight, &weaponTopLeft, &weaponBottomRight)){
            self->hit = true;
        } 
    } else if (self->type == bullseye){
        // width and height of hitbox
        float width = (float)self->alive->a[0]->width;
        float height = (float)self->alive->a[0]->height;
        // bounding box
        vector topLeft = {self->v->x, self->v->y + (0.25)*height};
        vector bottomRight = {self->v->x + width, self->v->y + (0.75)*height};
    
        if (checkBoundingBox(&topLeft, &bottomRight, &weaponTopLeft, &weaponBottomRight)){
            self->hit = true;
        } 
    } else if (self->type == butterfly || self->type == slime || 
               self->type == fire || self->type == vulture ||
               self->type == wind){
        // width and height of hitbox
        float width = (float)self->alive->a[0]->width;
        float height = (float)self->alive->a[0]->height;
        // bounding box, top left of the sprite is the coordinates of enemy
        vector bottomRight = {self->v->x + width, self->v->y + height};
    
        if (checkBoundingBox(self->v, &bottomRight, &weaponTopLeft, &weaponBottomRight)){
            self->hit = true;
        } 
    }
    
    // check hero collision
    if (self->type == slime || self->type == fire || self->type == vulture ||
        self->type == wind){
        float width = (float)self->alive->a[0]->width;
        float height = (float)self->alive->a[0]->height;
        // bounding box, top left of the sprite is the coordinates of enemy
        vector bottomRight = {self->v->x + width, self->v->y + height};
        
        // get bottom right corner of hero
        vector heroBottomRight = {h->v->x + h->alive->a[0]->width,
                                  h->v->y + h->alive->a[0]->height};
    
        if (checkBoundingBox(self->v, &bottomRight, h->v, &heroBottomRight)){
            h->hit = true;
        } 
    }
}


// destruct enemy
// caller frees self
static void destructEnemy(enemy *self){
    // free animations
    printDebugMessage("Calling destructAnimation(self->alive)");
    self->alive->destructAnimation(self->alive);
    printDebugMessage("Destructed self->alive");
    
    self->dead->destructAnimation(self->dead);
    printDebugMessage("Destructed self->dead");
    
    free(self->alive);
    printDebugMessage("Freed self->alive");
    
    free(self->dead);
    printDebugMessage("Freed self->dead");
    
    // free vector
    free(self->v);
    printDebugMessage("Freed self->v");
    
    printDebugMessage("END destructEnemy");
}


enemy *initEnemy(enum enemies e){
    enemy *self = malloc(sizeof(enemy));
    
    if (!self) printDebugMessage("Failed to allocate enemy *self");
    
    // init vector
    self->v = initVector();

    // init variables
    self->type = e;
    self->hit = false;
    self->offScreen = true;
    
    // init functions for enemy
    self->checkCollison = checkCollison;
    self->move = move;
    self->initLocation = initLocation;
    self->destructEnemy = destructEnemy;
    self->playNextAnimation = playNextAnimation;
    
    // init animations
    self->alive = initAnimation();
    self->dead = initAnimation();
    
    // load animations based off type
    if (e == redBalloon){
        int aliveSize = 1;
        int deadSize = 1;
        const char *redBalloonAlive[] = {"/balloon.sprite"};
        const char *redBalloonDead[] = {"/balloon_dead.sprite"};
        
        self->alive->addAnimations(self->alive, redBalloonAlive, aliveSize);
        self->dead->addAnimations(self->dead, redBalloonDead, deadSize);
    } else if (e == yellowBalloon){
        int aliveSize = 1;
        int deadSize = 1;
        const char *yellowBalloonAlive[] = {"/balloon_y.sprite"};
        const char *yellowBalloonDead[] = {"/balloon_y_dead.sprite"};
        
        self->alive->addAnimations(self->alive, yellowBalloonAlive, aliveSize);
        self->dead->addAnimations(self->dead, yellowBalloonDead, deadSize);
    } else if (e == butterfly){
        int aliveSize = 1;
        int deadSize = 1;
        const char *butterflyAlive[] = {"/butterfly_trapped.sprite"};
        const char *butterflyDead[] = {"/butterfly.sprite"};
        
        self->alive->addAnimations(self->alive, butterflyAlive, aliveSize);
        self->dead->addAnimations(self->dead, butterflyDead, deadSize);
    } else if (e == fire){
        int aliveSize = 4;
        int deadSize = 5;
        const char *fireAlive[] = {"/fire1.sprite", "/fire1.sprite",
                                   "/fire2.sprite", "/fire2.sprite"};
        const char *fireDead[] = {"/fire_dead.sprite", "/fire_dead.sprite",
             "/fire_dead.sprite", "/fire_dead.sprite", "/fire_dead.sprite"};
        
        self->alive->addAnimations(self->alive, fireAlive, aliveSize);
        self->dead->addAnimations(self->dead, fireDead, deadSize);
    } else if (e == slime){
        int aliveSize = 1;
        int deadSize = 5;
        
        const char *slimeAlive[] = {"/slime.sprite"};
        const char *slimeDead[] = {"/slime_dead.sprite", "/slime_dead.sprite", 
             "/slime_dead.sprite", "/slime_dead.sprite", "/slime_dead.sprite"};
        
        self->alive->addAnimations(self->alive, slimeAlive, aliveSize);
        self->dead->addAnimations(self->dead, slimeDead, deadSize);
    } else if (e == vulture){
        int aliveSize = 4;
        int deadSize = 4;
        
        const char *vultureAlive[] = {"/vulture1.sprite", "/vulture1.sprite",
                                      "/vulture2.sprite", "/vulture2.sprite"};
        const char *vulturenDead[] = {"/vulture_dead.sprite", "/vulture_dead.sprite",
                                      "/vulture_dead.sprite", "/vulture_dead.sprite"};
        
        self->alive->addAnimations(self->alive, vultureAlive, aliveSize);
        self->dead->addAnimations(self->dead, vulturenDead, deadSize);
    } else if (e == wind){
        int aliveSize = 4;
        int deadSize = 5;
        
        const char *windAlive[] = {"/wind1.sprite", "/wind1.sprite",
                                   "/wind2.sprite", "/wind2.sprite"};
        const char *windDead[] = {"/wind_dead.sprite", "/wind_dead.sprite",
                                  "/wind_dead.sprite", "/wind_dead.sprite"};
        
        self->alive->addAnimations(self->alive, windAlive, aliveSize);
        self->dead->addAnimations(self->dead, windDead, deadSize);
    } else if (e == scroll){
        int aliveSize = 1;
        int deadSize = 1;
        const char *scrollAlive[] = {"/scroll.sprite"};
        const char *scrollDead[] = {"/scroll.sprite"};
        
        self->alive->addAnimations(self->alive, scrollAlive, aliveSize);
        self->dead->addAnimations(self->dead, scrollDead, deadSize);
    } else if (e == bullseye){
        int aliveSize = 1;
        int deadSize = 1;
        const char *bullseyeAlive[] = {"/bulls_eye.sprite"};
        const char *bullseyeDead[] = {"/bulls_eye.sprite"};
        
        self->alive->addAnimations(self->alive, bullseyeAlive, aliveSize);
        self->dead->addAnimations(self->dead, bullseyeDead, deadSize);
    } else if (e == dove){
        int aliveSize = 2;
        int deadSize = 1;
        const char *doveAlive[] = {"/dove1.sprite", "/dove2.sprite"};
        const char *doveDead[] = {"/null.sprite"};
        
        self->alive->addAnimations(self->alive, doveAlive, aliveSize);
        self->dead->addAnimations(self->dead, doveDead, deadSize);
    } else if (e == tree){
        int aliveSize = 2;
        int deadSize = 1;
        const char *treeAlive[] = {"/tree1.sprite", "/tree2.sprite"};
        const char *treeDead[] = {"/tree_dead.sprite"};
        
        self->alive->addAnimations(self->alive, treeAlive, aliveSize);
        self->dead->addAnimations(self->dead, treeDead, deadSize);
    } else if (e == flame){
        int aliveSize = 1;
        int deadSize = 1;
        const char *flameAlive[] = {"/flame.sprite"};
        const char *flameDead[] = {"/null.sprite"};
        
        self->alive->addAnimations(self->alive, flameAlive, aliveSize);
        self->dead->addAnimations(self->dead, flameDead, deadSize);
    } else if (e == watcher){
        int aliveSize = 1;
        int deadSize = 1;
        const char *watcherAlive[] = {"/watcher1.sprite"};
        const char *watcherDead[] = {"/watcher2.sprite"};
        
        self->alive->addAnimations(self->alive, watcherAlive, aliveSize);
        self->dead->addAnimations(self->dead, watcherDead, deadSize);
    } else if (e == fairy){
        int aliveSize = 1;
        int deadSize = 1;
        const char *fairyAlive[] = {"/fairy_trapped.sprite"};
        const char *fairyDead[] = {"/fairy.sprite"};
        
        self->alive->addAnimations(self->alive, fairyAlive, aliveSize);
        self->dead->addAnimations(self->dead, fairyDead, deadSize);
    } else if (e == flashm1){
        int aliveSize = 1;
        int deadSize = 1;
        const char *flashm1Alive[] = {"/flashm1.sprite"};
        const char *flashm1Dead[] = {"/flashm1.sprite"};
        
        self->alive->addAnimations(self->alive, flashm1Alive, aliveSize);
        self->dead->addAnimations(self->dead, flashm1Dead, deadSize);
    } else if (e == flashm2){
        int aliveSize = 1;
        int deadSize = 1;
        const char *flashm2Alive[] = {"/flashm2.sprite"};
        const char *flashm2Dead[] = {"/flashm2.sprite"};
        
        self->alive->addAnimations(self->alive, flashm2Alive, aliveSize);
        self->dead->addAnimations(self->dead, flashm2Dead, deadSize);
    } else if (e == flashm3){
        int aliveSize = 1;
        int deadSize = 1;
        const char *flashm3Alive[] = {"/flashm3.sprite"};
        const char *flashm3Dead[] = {"/flashm3.sprite"};
        
        self->alive->addAnimations(self->alive, flashm3Alive, aliveSize);
        self->dead->addAnimations(self->dead, flashm3Dead, deadSize);
    }
            
    return self;
}