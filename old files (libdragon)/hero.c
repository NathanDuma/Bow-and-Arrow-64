/* 
 * File:   hero.c
 * Author: Nathan Duma
 *
 */

#include "hero.h"


// play the next animation

static void playNextAnimation(hero *self, display_context_t *disp, bool pressed) {
    animation *playNext;
    // get correct animation to play when hit or not
    if (!self->hit) {
        playNext = self->alive;
    } else {
        playNext = self->dead;
    }
    // draw the player
    if (playNext != NULL) {
        // only change animation when pressed
        if (pressed && (self->quiverCount > 0)) playNext->state = (int) (playNext->state + 1) % playNext->size;
        graphics_draw_sprite_trans(*disp, self->v->x,
                self->v->y, playNext->a[(int) playNext->state]);
        // if the arrow went from shooting to neutral, fire the weapon
        if (pressed && (playNext->state == 0) && (self->quiverCount > 0)) {
            // make a new arrow and place it at (self->v->x, self->v->y)
            self->w = addllist(self->w, initWeapon(arrows));
            if (!self->w) printDebugMessage("Failed to allocate self->w->node");
            ((weapon*) self->w->node)->v->x = self->v->x;
            ((weapon*) self->w->node)->v->y = self->v->y;

            // shoot the arrow
            ((weapon*) self->w->node)->shoot(self->w->node);

            self->quiverCount--;
        }
    }

    playNext = NULL;
    free(playNext);
}


// move the character up and down by inc units

static void move(hero *self, enum direction d) {
    float inc = 10.0;
    if (d == up) {
        self->v->y -= inc;
    } else {
        self->v->y += inc;
    }

    int heroMoveBoundary = 50;
    // we need to let the hero not go out of screen bounds
    if (self->v->y < -heroMoveBoundary) {
        self->v->y = -heroMoveBoundary;
    } else if (self->v->y > (SCREENHEIGHT - heroMoveBoundary)) {
        self->v->y = SCREENHEIGHT - heroMoveBoundary;
    }
}


// destructor for hero struct
// caller frees self

static void destructHero(hero *self) {
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

    // free weapons
    printDebugMessage("Calling destructWeapon(self->w[i])");
    for (llist *itWeapon = self->w; itWeapon; itWeapon = itWeapon->next) {
        ((weapon*) itWeapon->node)->destructWeapon(itWeapon->node);
    }
    printDebugMessage("Freed self->w[i]");

    printDebugMessage("Freeing self->w");
    destructllist(self->w);

    free(self->w);
    printDebugMessage("Freed self->w[i]");

    printDebugMessage("END destructHero");
}

hero *initHero(enum heros h, int quiverMax) {
    hero *self = malloc(sizeof (hero));

    if (!self) printDebugMessage("Failed to allocate hero *self");

    // initialize type
    self->type = h;
    // initialize hit
    self->hit = false;
    // initialize  vector
    self->v = initVector();

    self->w = NULL;

    if (h == normal) {
        // there are 4 animations for the normal hero
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

        self->w = NULL;
    }


    // initialize hero functions
    self->destructHero = destructHero;
    self->move = move;
    self->playNextAnimation = playNextAnimation;

    self->v->x = 0.0;
    self->v->y = rand() % SCREENHEIGHT;

    return self;
}

