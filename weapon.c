/* 
 * File:   weapon.h
 * Author: Nathan Duma
 *
 */

#include "weapon.h"
#include "common.h"


static Sprite *arrow[] = {
    &arrow_sprite
};

static Sprite *arrowFire[] = {
    &arrow_fire_sprite
};

static Sprite *apple[] = {
    &apple_sprite
};

static Sprite *thunderbolt[] = {
    &thunderbolt_sprite
};

static bool checkOffScreen(vector2D *v) {
    return (v->x > SCREEN_WD || v->x < 0) ||
            (v->y > SCREEN_HT || v->y < 0);
}

static bool checkBoundingBox(vector2D *topLeftR1, vector2D *bottomRightR1,
        vector2D *topLeftR2, vector2D *bottomRightR2) {
    return !((topLeftR1->x > bottomRightR2->x) || (bottomRightR1->x < topLeftR2->x) ||
            (topLeftR1->y > bottomRightR2->y) || (bottomRightR1->y < topLeftR2->y));
}

static void updatePosition(weapon *self) {
    if (self->offScreen == true) {
        return;
    }

    switch (self->type) {
        case arrows:
            self->v.x += self->speed;
            break;
        case thunder:
            self->v.x -= self->speed;
            break;
        case apples:
            self->v.x -= self->speed;
            break;
        case firearrow:
            self->v.x += self->speed;
            break;
        default:
            break;
    }
    if (checkOffScreen(&self->v)) {
        self->offScreen = true;

        // set it off screen now
        self->v.x = -100.0;
        self->v.y = -100.0;
    }
}

static void drawWeapon(weapon *self, Gfx **glistp) {
    Gfx *gp;

    // cheap check: don't draw if not on screen
    if (self->offScreen == true) {
        return;
    }

    gp = *glistp;

    // draw teh animation
    self->a.drawAnimation(&self->a, &gp, &self->v);

    *glistp = gp;
}

static void shoot(weapon *self) {
    // we need to fix the position of the weapon to be in front of hero when shot
    float weaponBaseX = 0.0;
    float weaponBaseY = 0.0;

    self->shot = true;
    self->offScreen = false;
    self->speed = 0.0;

    switch (self->type) {
        case arrows:
            weaponBaseX = 45.0 * 0.7;
            weaponBaseY = 40.0 * 0.7;
            self->speed = 1.2;
            break;
        case apples:
            weaponBaseX = 45.0 * 0.7;
            weaponBaseY = 40.0 * 0.7;
            self->speed = 1.2;
            break;
        case thunder:
            weaponBaseX = 45.0 * 0.7;
            weaponBaseY = 40.0 * 0.7;
            self->speed = 1.2;
            break;
        case firearrow:
            weaponBaseX = 0;
            weaponBaseY = 0;
            self->speed = 2.0;
        default:
            weaponBaseX = 45.0 * 0.7;
            weaponBaseY = 40.0 * 0.7;
            self->speed = 2.0;
            break;
    }

    // set position of weapon
    self->v.x = self->v.x + weaponBaseX;
    self->v.y = self->v.y + weaponBaseY;
}


// check if apple/thunder collide with the arrow

void checkCollisonWithWeapon(weapon *w1, weapon *w2) {
    int width;
    int height;
    vector2D weapon1BottomRight;
    vector2D weapon2BottomRight;
    

    if (w1->offScreen || w2->offScreen) {
        return;
    }


    switch (w1->type) {
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

    weapon1BottomRight.x = w1->v.x + width * w1->scale.x;
    weapon1BottomRight.y = w1->v.y + height * w1->scale.y;

    switch (w2->type) {
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
    
    weapon2BottomRight.x = w2->v.x + width * w2->scale.x;
    weapon2BottomRight.y = w2->v.y + height * w2->scale.y;

    // now check if weapon hit hero
    if(checkBoundingBox(&w1->v, &weapon1BottomRight,
            &w2->v, &weapon2BottomRight)){
        // set both weapons off screen
        w1->offScreen = true;
        w2->offScreen = true;

        // set it off screen now
        w1->v.x = -100.0;
        w1->v.y = -100.0;
        
        w2->v.x = -100.0;
        w2->v.y = -100.0;
    }
}

static void destructWeapon(weapon *self) {
    self->a.destructAnimation(&self->a);
}

void initWeapon(weapon *self, weaponType t) {
    self->type = t;
    self->shot = false;
    self->offScreen = true;

    initVector2D(&self->v);
    initVector2D(&self->scale);

    self->scale.x = 0.7F;
    self->scale.y = 0.7F;


    switch (self->type) {
        case arrows:
            initAnimation(&self->a, arrow,
                    sizeof (arrow) / sizeof (arrow[0]), &self->scale);
            break;
        case thunder:
            initAnimation(&self->a, thunderbolt,
                    sizeof (thunderbolt) / sizeof (thunderbolt[0]), &self->scale);
            break;
        case apples:
            initAnimation(&self->a, apple,
                    sizeof (apple) / sizeof (apple[0]), &self->scale);
            break;
        case firearrow:
            initAnimation(&self->a, arrowFire,
                    sizeof (arrowFire) / sizeof (arrowFire[0]), &self->scale);

            self->offScreen = false;
            break;
        default:
            initAnimation(&self->a, arrowFire,
                    sizeof (arrowFire) / sizeof (arrowFire[0]), &self->scale);
            break;
            break;
    }

    self->destructWeapon = destructWeapon;
    self->shoot = shoot;
    self->drawWeapon = drawWeapon;
    self->checkCollisonWithWeapon = checkCollisonWithWeapon;
    self->updatePosition = updatePosition;
}
