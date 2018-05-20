/* 
 * File:   hero.c
 * Author: Nathan Duma
 *
 */

#include "hero.h"
#include "common.h"
#include "cont.h"
#include "common_sprites.h"

static Sprite *normalHeroAlive[] = {
    &hero0_sprite,
    &hero1_sprite,
    &hero2_sprite,
    &hero3_sprite
};

static Sprite *normalHeroDead[] = {
    &hero_dead_sprite
};


// check bounding box for collison test

static bool checkBoundingBox(vector2D *topLeftR1, vector2D *bottomRightR1,
        vector2D *topLeftR2, vector2D *bottomRightR2) {
    return !((topLeftR1->x > bottomRightR2->x) || (bottomRightR1->x < topLeftR2->x) ||
            (topLeftR1->y > bottomRightR2->y) || (bottomRightR1->y < topLeftR2->y));
}

static int draw = 0;
// play the next animation

static void drawHero(hero *self, Gfx **glistp) {
    Gfx *gp;
    int i;

    static bool updateDraw = false;

    // cheap check: don't draw if not on screen
    if (self->hidden == true) {
        return;
    }

    if (contdata[0].trigger & A_BUTTON) {
        updateDraw = true;
    }

    gp = *glistp;

    // play dead because hit
    if (self->hit) {
        // only switch the animation every 7 frames
        if (draw >= 7) {
            self->dead.state++;
            draw = 0;
        }

        self->dead.drawAnimation(&self->dead, &gp, &self->v);
    } else {
        // only switch the animation every 5 frames
        if (draw >= 5) {

            // only change animations if we have quiver
            if (self->quiverCount) {
                self->alive.state++;
            }

            // don't change the last animation until we have released A
            if ((self->alive.state == 4) &&
                    (contdata[0].button & A_BUTTON)) {
                self->alive.state--;
            }


            // done animating, shoot waepon
            if ((self->alive.state >= 4) &&
                    (self->quiverCount > 0) &&
                    (self->w != NULL) &&
                    !(contdata[0].button & A_BUTTON)) {

                i = self->quiverCount - 1;
                self->w[i].v.x = self->v.x;
                self->w[i].v.y = self->v.y;

                self->w[i].shoot(&self->w[i]);

                self->quiverCount--;
                updateDraw = false;
            }

            draw = 0;
        }

        self->alive.drawAnimation(&self->alive, &gp, &self->v);
    }

    // draw the weapons now
    for (i = 0; i < self->quiverMax; i++) {
        self->w[i].updatePosition(&self->w[i]);
        self->w[i].drawWeapon(&self->w[i], &gp);
    }

    if (updateDraw) {
        draw++;
    }

    *glistp = gp;
}

// check if the enemy's weapon collides with hero

static void checkCollisonWithWeapon(hero *self, weapon *w) {
    int width;
    int height;
    vector2D weaponBottomRight;
    vector2D heroBottomRight;

    if (self->hit || w->offScreen) {
        return;
    }


    switch (w->type) {
        case arrows:
            width = arrowTRUEIMAGEW;
            height = arrowTRUEIMAGEH;
            break;
        case apples:
            width = appleTRUEIMAGEW;
            height = appleTRUEIMAGEH;
            break;
        case thunder:
            width = thunderboltTRUEIMAGEW;
            height = thunderboltTRUEIMAGEH;
            break;
        case firearrow:
            width = arrow_fireTRUEIMAGEW;
            height = arrow_fireTRUEIMAGEH;
            break;
        default:
            width = arrowTRUEIMAGEW;
            height = arrowTRUEIMAGEH;
            break;
    };

    weaponBottomRight.x = w->v.x + width * w->scale.x;
    weaponBottomRight.y = w->v.y + height * w->scale.y;

    heroBottomRight.x = self->v.x + hero0TRUEIMAGEW * self->scale.x - 10;
    heroBottomRight.y = self->v.y + hero0TRUEIMAGEH * self->scale.y - 10;

    // now check if weapon hit hero
    self->hit = checkBoundingBox(&self->v, &heroBottomRight,
            &w->v, &weaponBottomRight);
}


// move the character up and down by inc units

static void move(hero *self, direction d) {
    float inc;
    float heroMoveBoundary;

    if (contdata->stick_y > 5 || contdata->stick_y < -5) {
        inc = -5.0 * (float) (contdata->stick_y) / 80.0;
    } else if (contdata[0].button & D_JPAD) {
        inc = 3.0;
    } else if (contdata[0].button & U_JPAD) {
        inc = -3.0;
    } else {
        inc = 0.0;
    }


    self->v.y += inc;

    heroMoveBoundary = 50.0;
    // we need to let the hero not go out of screen bounds
    if (self->v.y < -heroMoveBoundary) {
        self->v.y = -heroMoveBoundary;
    } else if (self->v.y > (float) (SCREEN_HT - heroMoveBoundary)) {
        self->v.y = (float) (SCREEN_HT - heroMoveBoundary);
    }
}


// destructor for hero struct
// caller frees self

static void destructHero(hero *self) {
    int i;
    // free weapons
    for (i = 0; i < self->quiverMax; i++) {
        self->w[i].destructWeapon(&self->w[i]);
    }
    free(self->w);

    // free animations
    self->alive.destructAnimation(&self->alive);
    self->dead.destructAnimation(&self->dead);
}

void initHero(hero *self, heroType h, int quiverMax) {
    int i;
    
    draw = 0;

    self->type = h;

    self->quiverMax = quiverMax;
    self->quiverCount = quiverMax;
    self->hit = false;
    self->hidden = false;
    self->w = NULL;

    initVector2D(&self->v);
    self->v.y = SCREEN_HT / 2;

    initVector2D(&self->scale);
    self->scale.x = 0.7F;
    self->scale.y = 0.7F;

    initAnimation(&self->alive, normalHeroAlive,
            sizeof (normalHeroAlive) / sizeof (normalHeroAlive[0]), &self->scale);
    initAnimation(&self->dead, normalHeroDead,
            sizeof (normalHeroDead) / sizeof (normalHeroDead[0]), &self->scale);

    if (h == normal) {
        // initialize the weapons
        self->w = malloc(sizeof (weapon) * self->quiverMax);

        for (i = 0; i < self->quiverMax; i++) {
            initWeapon(&self->w[i], arrows);
        }
    }

    if (self->w == NULL) {
        errors |= ERRORFLAG2;
    }

    // initialize hero functions
    self->destructHero = destructHero;
    self->move = move;
    self->drawHero = drawHero;
    self->checkCollisonWithWeapon = checkCollisonWithWeapon;
}
