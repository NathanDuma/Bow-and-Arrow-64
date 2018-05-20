/* 
 * File:   enemy.c
 * Author: Nathan Duma
 *
 */


#include "enemy.h"
#include "common_sprites.h"

static Sprite *redBalloonAlive [] = {
    &balloon_sprite
};

static Sprite *redBalloonDead [] = {
    &balloon_dead_sprite
};

static Sprite *yellowBalloonAlive [] = {
    &balloon_y_sprite
};

static Sprite *yellowBalloonDead [] = {
    &balloon_y_dead_sprite
};

static Sprite *butterflyAlive [] = {
    &butterfly_trapped_sprite
};

static Sprite *butterflyDead [] = {
    &butterfly_sprite
};

static Sprite *bullseyeAlive [] = {
    &bulls_eye_sprite
};

static Sprite *bullseyeDead [] = {
    &bulls_eye_sprite
};

static Sprite *fireAlive [] = {
    &fire1_sprite,
    &fire2_sprite
};

static Sprite *fireDead [] = {
    &fire_dead_sprite
};

static Sprite *slimeAlive [] = {
    &slime_sprite
};

static Sprite *slimeDead [] = {
    &slime_dead_sprite
};

static Sprite *vultureAlive [] = {
    &vulture1_sprite,
    &vulture2_sprite
};

static Sprite *vultureDead [] = {
    &vulture_dead_sprite
};

static Sprite *windAlive [] = {
    &wind1_sprite,
    &wind2_sprite
};

static Sprite *windDead [] = {
    &wind_dead_sprite
};

static Sprite *watcherAlive [] = {
    &watcher1_sprite
};

static Sprite *watcherDead [] = {
    &watcher2_sprite
};

static Sprite *fairyAlive [] = {
    &fairy_trapped_sprite,
};

static Sprite *fairyDead [] = {
    &fairy_sprite
};

static Sprite *flashmAlive [] = {
    &flashm1_sprite,
    &flashm2_sprite
};

static Sprite *flashmDead [] = {
    &flashm3_sprite
};

static Sprite *treeAlive [] = {
    &tree1_sprite,
    &tree2_sprite
};

static Sprite *treeDead [] = {
    &tree_dead_sprite
};

static Sprite *scrollAlive [] = {
    &scroll_sprite
};

static Sprite *scrollDead [] = {
    &scroll_sprite
};

static Sprite *doveAlive [] = {
    &dove1_sprite,
    &dove2_sprite
};

static Sprite *doveDead [] = {
    &dove2_sprite
};

static Sprite *errorAlive [] = {
    &hero_random_sprite
};

static Sprite *errorDead [] = {
    &hero_random_sprite
};

static Sprite *flameAlive[] = {
    &flame_sprite
};

static Sprite *flameDead[] = {
    &flame_sprite
};




// check if two rectangles (hitboxes) collide

static bool checkBoundingBox(vector2D *topLeftR1, vector2D *bottomRightR1,
        vector2D *topLeftR2, vector2D *bottomRightR2) {
    return !((topLeftR1->x > bottomRightR2->x) || (bottomRightR1->x < topLeftR2->x) ||
            (topLeftR1->y > bottomRightR2->y) || (bottomRightR1->y < topLeftR2->y));
}

// check if the object is off screen

static bool checkOffScreen(vector2D *v) {
    return (v->x > SCREEN_WD || v->x < 0) ||
            (v->y > SCREEN_HT || v->y < 0);
}

static void shootWatcher(enemy *self) {
    static int shootableWeapon1 = 0;
    if (shootableWeapon1 == self->weaponCount) {
        shootableWeapon1 = 0;
    }

    self->w[shootableWeapon1].v.x = self->v.x - thunderboltTRUEIMAGEW * self->scale.x;
    self->w[shootableWeapon1].v.y = self->v.y;

    self->w[shootableWeapon1].shoot(&self->w[shootableWeapon1]);


    shootableWeapon1++;
}

static void shootTree(enemy *self) {
    static int shootableWeapon2 = 0;
    if (shootableWeapon2 == self->weaponCount) {
        shootableWeapon2 = 0;
    }

    self->w[shootableWeapon2].v.x = self->v.x - tree1TRUEIMAGEW * self->scale.x;
    self->w[shootableWeapon2].v.y = self->v.y - 15;

    self->w[shootableWeapon2].shoot(&self->w[shootableWeapon2]);


    shootableWeapon2++;
}

static void drawEnemy(enemy *self, Gfx **glistp) {
    Gfx *gp;
    int threshhold;
    int i;
    bool treeShoot;

    //self->move(self);

    if (self->offScreen == true || self->deadCounter > 15) {
        self->offScreen = true;

        // the tree is dead, but draw the remaining weapons
        if (self->type == tree) {
            for (i = 0; i < self->weaponCount; i++) {
                self->w[i].drawWeapon(&self->w[i], &gp);
            }
            
            //*glistp = gp;
        }
        return;
    }

    gp = *glistp;

    treeShoot = false;

    // play dead because hit
    if (self->hit == true) {
        self->dead.drawAnimation(&self->dead, &gp, &self->v);

        // we need to know when to shoot
        // for the watcher
        if (self->type == watcher) {
            self->draw++;
            self->hostile = true;
        }

        // enemies need to be put off screen
        if (!(self->type == redBalloon ||
                self->type == yellowBalloon ||
                self->type == butterfly ||
                self->type == watcher ||
                self->type == fairy ||
                self->type == flame)) {
            self->deadCounter++;
        }
    } else {
        // how often we switch the animation
        switch (self->type) {
            case redBalloon:
                threshhold = 0;
                break;
            case yellowBalloon:
                threshhold = 0;
                break;
            case butterfly:
                threshhold = 0;
                break;
            case fire:
                threshhold = 8;
                break;
            case slime:
                threshhold = 0;
                break;
            case vulture:
                threshhold = 15;
                break;
            case wind:
                threshhold = 8;
                break;
            case scroll:
                threshhold = 0;
                break;
            case bullseye:
                threshhold = 0;
                break;
            case dove:
                threshhold = 15;
                break;
            case tree:
                threshhold = 60;
                break;
            case flame:
                threshhold = 16;
                break;
            case watcher:
                threshhold = 0;
                break;
            case fairy:
                threshhold = 0;
                break;
            case flashm:
                threshhold = 17;
                break;
            default:
                threshhold = 0;
                break;
        }

        if (self->draw >= threshhold) {
            if ((self->alive.state == 1) &&
                    (self->type == tree &&
                    !self->hit)) {
                treeShoot = true;
            }
            self->alive.state++;
            self->draw = 0;
        }

        self->draw++;

        self->alive.drawAnimation(&self->alive, &gp, &self->v);
    }

    // shoot every 49 frames for the watcher
    if ((self->type == watcher) &&
            (self->hostile == true) &&
            self->draw > 49) {
        shootWatcher(self);
        self->draw = 0;
    } else if (treeShoot) {
        shootTree(self);
    }

    // draw all the weapons on the screen that the enemy has
    for (i = 0; i < self->weaponCount; i++) {
        if ((self->type == watcher && self->hostile == true) ||
                (self->type == tree && !self->hit)) {
            self->w[i].drawWeapon(&self->w[i], &gp);
        }
    }

    *glistp = gp;
}

// move the specific enemy
// some enemies share the same movement types

static void move(enemy *self) {
    float inc;

    if (!checkOffScreen(&self->v)) {
        self->offScreen = false;
    }

    if (!self->hit) { // alive animations
        if (self->type == redBalloon || self->type == flame) {
            inc = 0.7;
            self->v.y = self->v.y - inc;

            if (self->v.y < 0) {
                self->v.y = (float) SCREEN_HT;
            }
        } else if (self->type == yellowBalloon) {
            inc = 1.0;
            self->v.y = self->v.y - inc;

            if (self->v.y < 0) {
                self->v.y = (float) SCREEN_HT;
            }
        } else if (self->type == butterfly || self->type == bullseye ||
                self->type == watcher || self->type == fairy) {
            inc = 0.8;
            if (self->v.d == up) {
                self->v.y -= inc;
            } else if (self->v.d == down) {
                self->v.y += inc;
            }

            // check if the butterfly is out of bounds
            if (self->v.y > SCREEN_WD) {
                self->v.d = up;
                self->v.y = SCREEN_HT;
            } else if (self->v.y < 0) {
                self->v.d = down;
                self->v.y = 0;
            }
        } else if (self->type == slime || self->type == fire ||
                self->type == vulture || self->type == wind ||
                self->type == flashm) {
            inc = 0.8;
            self->v.x -= inc;
            if (self->v.x < 0) { // off screen
                self->hit = true;
            }
        } else if (self->type == dove) {
            inc = 0.6;

            // y is going to be a quadratic function
            // step the x value by inc every time
            self->v.y -= inc;
            self->v.x -= inc;
        }
    } else { // dead animations
        if (checkOffScreen(&self->v) &&
                self->type != watcher &&
                self->type != flame) {
            // put the enemy off screen at (-100, -100)
            self->v.x = -100;
            self->v.y = -100;

            // set the enemy off screen
            self->offScreen = true;
        }
        if (self->type == flame) {
            inc = 0.7;
            self->v.y = self->v.y - inc;

            if (self->v.y < 0) {
                self->v.y = (float) SCREEN_HT;
            }
        } else if (self->type == redBalloon || self->type == yellowBalloon) {
            inc = 1.0;
            self->v.y += inc;
        } else if (self->type == butterfly || self->type == fairy) {

            inc = 1.0;
            self->v.x -= inc;
            self->v.y -= inc;
        } else if (self->type == watcher) {
            inc = 0.8;
            if (self->v.d == up) {
                self->v.y -= inc;
            } else if (self->v.d == down) {
                self->v.y += inc;
            }

            // check if the watcher is out of bounds
            if (self->v.y > SCREEN_WD) {
                self->v.d = up;
                self->v.y = SCREEN_HT;
            } else if (self->v.y < 0) {
                self->v.d = down;
                self->v.y = 0;
            }
        }
    }
}

// check collison between the enemy and weapon

static void checkCollisonWithWeapon(enemy *self, weapon *w) {
    int width;
    int height;
    vector2D weaponTopLeft;
    vector2D weaponBottomRight;
    vector2D enemyTopLeft;
    vector2D enemyBottomRight;

    if (self->hit || w->offScreen ||
            (self->type == tree && w->type != firearrow)) {
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

    // if it's a bullseye then we only do the middle potion
    if (self->type == bullseye) {
        enemyTopLeft.x = self->v.x;
        enemyTopLeft.y = self->v.y + (bulls_eyeTRUEIMAGEH * self->scale.y / 2) - 5;

        enemyBottomRight.x = self->v.x + bulls_eyeTRUEIMAGEW * self->scale.x;
        enemyBottomRight.y = self->v.y + (bulls_eyeTRUEIMAGEH * self->scale.y / 2) + 5;

        if (checkBoundingBox(&enemyTopLeft, &enemyBottomRight,
                &w->v, &weaponBottomRight)) {
            self->hit = true;
        }
        return;
    }

    // get the bounding box and see if it collides with the weapon
    switch (self->type) {
        case redBalloon:
            width = balloonTRUEIMAGEW;
            height = balloonTRUEIMAGEH;
            break;
        case yellowBalloon:
            width = balloonTRUEIMAGEW;
            height = balloonTRUEIMAGEH;
            break;
        case butterfly:
            width = butterfly_trappedTRUEIMAGEW;
            height = butterfly_trappedTRUEIMAGEH;
            break;
        case fire:
            width = fire1TRUEIMAGEW;
            height = fire1TRUEIMAGEH;
            break;
        case slime:
            width = slimeTRUEIMAGEW;
            height = slimeTRUEIMAGEH;
            break;
        case vulture:
            width = slimeTRUEIMAGEW;
            height = slimeTRUEIMAGEH;
            break;
        case wind:
            width = wind1TRUEIMAGEW;
            height = wind1TRUEIMAGEH;
            break;
        case scroll:
            width = scrollTRUEIMAGEW;
            height = scrollTRUEIMAGEH;
            break;
        case bullseye:
            width = bulls_eyeTRUEIMAGEW;
            height = bulls_eyeTRUEIMAGEH;
            break;
        case dove:
            width = dove1TRUEIMAGEW;
            height = dove1TRUEIMAGEH;
            break;
        case tree:
            width = tree1TRUEIMAGEW;
            height = tree1TRUEIMAGEH;
            break;
        case flame:
            width = flameTRUEIMAGEW;
            height = flameTRUEIMAGEH;
            break;
        case watcher:
            width = watcher1TRUEIMAGEW;
            height = watcher1TRUEIMAGEH;
            break;
        case fairy:
            width = fairy_trappedTRUEIMAGEW;
            height = fairy_trappedTRUEIMAGEH;
            break;
        case flashm:
            width = flashm1TRUEIMAGEW;
            height = flashm1TRUEIMAGEH;
            break;
        default:
            width = scrollTRUEIMAGEW;
            height = scrollTRUEIMAGEH;
            break;
    }
    enemyBottomRight.x = self->v.x + width * self->scale.x;
    enemyBottomRight.y = self->v.y + height * self->scale.y;

    if (checkBoundingBox(&self->v, &enemyBottomRight, &w->v, &weaponBottomRight)) {
        self->hit = true;

        // make it a fire arrow now
        if (self->type == flame) {
            self->hit = false;

            // make the weapon into a firearrow now
            width = w->v.x;
            height = w->v.y;

            w->destructWeapon(w);
            initWeapon(w, firearrow);

            w->v.x = width;
            w->v.y = height;
        }

        // the dove was hit
        if (self->type == dove) {
            doveHit = true;
        }
    }
}


// check collison between the enemy and hero

static void checkCollisonWithHero(enemy *self, hero *h) {
    int width;
    int height;
    vector2D heroBottomRight;
    vector2D enemyBottomRight;

    if (self->hit || h->hit) {
        return;
    }

    // get the bounding box and see if it collides with the weapon
    switch (self->type) {
        case redBalloon:
            width = balloonTRUEIMAGEW;
            height = balloonTRUEIMAGEH;
            break;
        case yellowBalloon:
            width = balloonTRUEIMAGEW;
            height = balloonTRUEIMAGEH;
            break;
        case butterfly:
            width = butterfly_trappedTRUEIMAGEW;
            height = butterfly_trappedTRUEIMAGEH;
            break;
        case fire:
            width = fire1TRUEIMAGEW;
            height = fire1TRUEIMAGEH;
            break;
        case slime:
            width = slimeTRUEIMAGEW;
            height = slimeTRUEIMAGEH;
            break;
        case vulture:
            width = vulture1TRUEIMAGEW;
            height = vulture2TRUEIMAGEH;
            break;
        case wind:
            width = wind1TRUEIMAGEW;
            height = wind1TRUEIMAGEH;
            break;
        case scroll:
            width = scrollTRUEIMAGEW;
            height = scrollTRUEIMAGEH;
            break;
        case bullseye:
            width = bulls_eyeTRUEIMAGEW;
            height = bulls_eyeTRUEIMAGEH;
            break;
        case dove:
            width = dove1TRUEIMAGEW;
            height = dove1TRUEIMAGEH;
            break;
        case tree:
            width = tree1TRUEIMAGEW;
            height = tree1TRUEIMAGEH;
            break;
        case flame:
            width = flameTRUEIMAGEW;
            height = flameTRUEIMAGEH;
            break;
        case watcher:
            width = watcher1TRUEIMAGEW;
            height = watcher1TRUEIMAGEH;
            break;
        case fairy:
            width = fairy_trappedTRUEIMAGEW;
            height = fairy_trappedTRUEIMAGEH;
            break;
        case flashm:
            width = flashm1TRUEIMAGEW;
            height = flashm1TRUEIMAGEH;
            break;
        default:
            width = scrollTRUEIMAGEW;
            height = scrollTRUEIMAGEH;
            break;
    }
    enemyBottomRight.x = self->v.x + width * self->scale.x;
    enemyBottomRight.y = self->v.y + height * self->scale.y;

    // check hero collision
    if (self->type == slime || self->type == fire || self->type == vulture ||
            self->type == wind || self->type == flame || self->type == flashm) {
        // bounding box, bottom right of the sprite is the coordinates of enemy
        enemyBottomRight.x = self->v.x + width * self->scale.x;
        enemyBottomRight.y = self->v.y + height * self->scale.y;

        width = hero1TRUEIMAGEW;
        height = hero1TRUEIMAGEH;


        heroBottomRight.x = h->v.x + width * h->scale.x - 7;
        heroBottomRight.y = h->v.y + height * h->scale.y - 7;

        if (checkBoundingBox(&self->v, &enemyBottomRight, &h->v, &heroBottomRight)) {

            h->hit = true;
        }
    }
}


// destruct enemy
// caller frees self

static void destructEnemy(enemy *self) {
    int i;

    self->alive.destructAnimation(&self->alive);
    self->dead.destructAnimation(&self->dead);

    for (i = 0; i < self->weaponCount; i++) {
        self->w[i].destructWeapon(&self->w[i]);
    }
    free(self->w);
}

void initEnemy(enemy *self, enemyType t, int enemyStartX, int enemyStartY) {
    int i;

    // init vector
    initVector2D(&self->v);

    initVector2D(&self->scale);

    // scale for any enemy...
    self->scale.x = 1.0F;
    self->scale.y = 1.0F;

    self->v.x = (float) enemyStartX;
    self->v.y = (float) enemyStartY;

    // init variables
    self->type = t;
    self->hit = false;
    self->offScreen = true;
    self->hostile = false;
    self->deadCounter = 0;
    self->w = NULL;
    self->weaponCount = 0;

    // init functions for enemy
    self->checkCollisonWithHero = checkCollisonWithHero;
    self->checkCollisonWithWeapon = checkCollisonWithWeapon;
    self->move = move;
    self->destructEnemy = destructEnemy;
    self->drawEnemy = drawEnemy;

    // load animations based off type
    switch (t) {
        case redBalloon:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, redBalloonAlive,
                    sizeof (redBalloonAlive) / sizeof (redBalloonAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, redBalloonDead,
                    sizeof (redBalloonDead) / sizeof (redBalloonDead[0]),
                    &self->scale);
            break;
        case yellowBalloon:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, yellowBalloonAlive,
                    sizeof (yellowBalloonAlive) / sizeof (yellowBalloonAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, yellowBalloonDead,
                    sizeof (yellowBalloonDead) / sizeof (yellowBalloonDead[0]),
                    &self->scale);
            break;
        case butterfly:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, butterflyAlive,
                    sizeof (butterflyAlive) / sizeof (butterflyAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, butterflyDead,
                    sizeof (butterflyDead) / sizeof (butterflyDead[0]),
                    &self->scale);
            break;
        case fire:
            self->scale.x = 0.70F;
            self->scale.y = 0.70F;

            initAnimation(&self->alive, fireAlive,
                    sizeof (fireAlive) / sizeof (fireAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, fireDead,
                    sizeof (fireDead) / sizeof (fireDead[0]),
                    &self->scale);
            break;
        case slime:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, slimeAlive,
                    sizeof (slimeAlive) / sizeof (slimeAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, slimeDead,
                    sizeof (slimeDead) / sizeof (slimeDead[0]),
                    &self->scale);
            break;
        case vulture:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, vultureAlive,
                    sizeof (vultureAlive) / sizeof (vultureAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, vultureDead,
                    sizeof (vultureDead) / sizeof (vultureDead[0]),
                    &self->scale);
            break;
        case wind:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, windAlive,
                    sizeof (windAlive) / sizeof (windAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, windDead,
                    sizeof (windDead) / sizeof (windDead[0]),
                    &self->scale);
            break;
        case scroll:
            self->scale.x = 0.8F;
            self->scale.y = 0.8F;

            initAnimation2(&self->alive, scrollAlive,
                    sizeof (scrollAlive) / sizeof (scrollAlive[0]),
                    &self->scale);
            initAnimation2(&self->dead, scrollDead,
                    sizeof (scrollDead) / sizeof (scrollDead[0]),
                    &self->scale);
            break;
        case bullseye:
            self->scale.x = 1.0F;
            self->scale.y = 1.0F;

            initAnimation(&self->alive, bullseyeAlive,
                    sizeof (bullseyeAlive) / sizeof (bullseyeAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, bullseyeDead,
                    sizeof (bullseyeDead) / sizeof (bullseyeDead[0]),
                    &self->scale);
            break;
        case dove:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, doveAlive,
                    sizeof (doveAlive) / sizeof (doveAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, doveDead,
                    sizeof (doveDead) / sizeof (doveDead[0]),
                    &self->scale);
            break;
        case tree:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, treeAlive,
                    sizeof (treeAlive) / sizeof (treeAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, treeDead,
                    sizeof (treeDead) / sizeof (treeDead[0]),
                    &self->scale);

            self->weaponCount = 5;

            self->w = malloc(sizeof (weapon) * self->weaponCount);
            if (self->w == NULL) {
                errors |= ERRORFLAG6;
            }

            for (i = 0; i < self->weaponCount; i++) {
                initWeapon(&self->w[i], apples);
            }
            break;
        case watcher:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, watcherAlive,
                    sizeof (watcherAlive) / sizeof (watcherAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, watcherDead,
                    sizeof (watcherDead) / sizeof (watcherDead[0]),
                    &self->scale);
            self->weaponCount = 5;

            self->w = malloc(sizeof (weapon) * self->weaponCount);
            if (self->w == NULL) {
                errors |= ERRORFLAG7;
            }

            for (i = 0; i < self->weaponCount; i++) {
                initWeapon(&self->w[i], thunder);
            }

            break;
        case fairy:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, fairyAlive,
                    sizeof (fairyAlive) / sizeof (fairyAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, fairyDead,
                    sizeof (fairyDead) / sizeof (fairyDead[0]),
                    &self->scale);
            break;
        case flashm:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, flashmAlive,
                    sizeof (flashmAlive) / sizeof (flashmAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, flashmDead,
                    sizeof (flashmDead) / sizeof (flashmDead[0]),
                    &self->scale);
            break;
        case flame:
            self->scale.x = 0.55F;
            self->scale.y = 0.55F;

            initAnimation(&self->alive, flameAlive,
                    sizeof (flameAlive) / sizeof (flameAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, flameDead,
                    sizeof (flameDead) / sizeof (flameDead[0]),
                    &self->scale);
            break;
        default:
            self->scale.x = 1.0F;
            self->scale.y = 1.0F;

            initAnimation(&self->alive, errorAlive,
                    sizeof (errorAlive) / sizeof (errorAlive[0]),
                    &self->scale);
            initAnimation(&self->dead, errorDead,
                    sizeof (errorDead) / sizeof (errorDead[0]),
                    &self->scale);
            break;
    }
}
