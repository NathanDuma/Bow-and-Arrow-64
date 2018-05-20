/* 
 * File:   map.c
 * Author: Nathan Duma
 *
 */

#include "map.h"
#include <malloc.h>
#include "game_state.h"

static void drawMap(map *self, Gfx **glistp) {
    Gfx *gp;
    int i;

    gp = *glistp;

    self->h.drawHero(&self->h, &gp);

    for (i = 0; i < self->enemyCount; i++) {
        self->e[i].drawEnemy(&self->e[i], &gp);
    }

    *glistp = gp;
}

// update all the map objects

static void updateMap(map *self) {
    int i;
    int j;
    int k;
    int offScreenEnemyCount;
    int deadEnemyCount;
    bool completed;
    bool anyAlive;

    if (self->paused) {
        return;
    }

    completed = true;
    anyAlive = false;

    offScreenEnemyCount = 0;
    deadEnemyCount = 0;

    // update the enemy position
    // also check collisions with the enemy and hero
    for (i = 0; i < self->enemyCount; i++) {
        self->e[i].move(&self->e[i]);
        self->e[i].checkCollisonWithHero(&self->e[i], &self->h);

        // get dead enemy & off screen count
        if (self->e[i].hit == true) {
            deadEnemyCount++;
        }
        if (self->e[i].offScreen == true) {
            offScreenEnemyCount++;
        }
    }

    // update the weapon position for hero
    for (i = 0; i < self->h.quiverMax; i++) {
        self->h.w[i].updatePosition(&self->h.w[i]);
    }

    // check if the weapon collides with the enemy
    for (i = 0; i < self->enemyCount; i++) {
        for (j = 0; j < self->h.quiverMax; j++) {
            self->e[i].checkCollisonWithWeapon(&self->e[i], &self->h.w[j]);
        }
    }

    // update enemy weapons
    for (i = 0; i < self->enemyCount; i++) {
        if (self->e[i].w) {
            for (j = 0; j < self->e[i].weaponCount; j++) {
                self->e[i].w[j].updatePosition(&self->e[i].w[j]);
            }
        }
    }
    
    // check if hero weapon collides with enemy weapon
    for (i = 0; i < self->enemyCount; i++) {
        if (self->e[i].w) {
            for (j = 0; j < self->e[i].weaponCount; j++) {
                for (k = 0; k < self->h.quiverMax; k++){
                self->e[i].w[j].checkCollisonWithWeapon(&self->h.w[k], 
                        &self->e[i].w[j]);
                }
            }
        }
    }

    // check if enemy weapon collides with hero
    for (i = 0; i < self->enemyCount; i++) {
        if (self->e[i].w) {
            for (j = 0; j < self->e[i].weaponCount; j++) {
                self->h.checkCollisonWithWeapon(&self->h, &self->e[i].w[j]);
            }
        }
    }

    // now check for completion of the level.
    switch (self->mapNumber) {
        case 1:
            // all balloons are off screen OR no more arrows & all off screen

            // they are all dead and off screen
            if ((deadEnemyCount == self->enemyCount) &&
                    (offScreenEnemyCount == self->enemyCount)) {
                // go to next level
                self->mapNumber++;
                break;
            }

            // only check if we shot all of the arrows
            // and there are some enemies living
            if ((self->h.quiverCount == 0) &&
                    (deadEnemyCount != self->enemyCount)) {
                for (i = 0; i < self->h.quiverMax; i++) {
                    if (self->h.w[i].offScreen == false) {
                        // there are still weapons on the screen
                        // so keep playing
                        return;
                    }
                }

                // all weapons off screen, so now play no arrows sequence
                self->h.hit = true;
            }

            break;
        case 3:
            // all red balloons are off screen OR no more arrows & all off screen

            // delete all the yellow balloons that are in the dead/offscreen 
            // count because we don't care if they die or not this level
            for (i = (self->enemyCount - 5); i < self->enemyCount; i++) {
                // get dead enemy & off screen count
                if (self->e[i].hit == true) {
                    deadEnemyCount--;
                }
                if (self->e[i].offScreen == true) {
                    offScreenEnemyCount--;
                }
            }

            // they are all dead and off screen
            if ((deadEnemyCount == (self->enemyCount - 5)) &&
                    (offScreenEnemyCount == (self->enemyCount - 5))) {
                // go to next level
                self->mapNumber++;
                break;
            }

            // only check if we shot all of the arrows
            // and there are some enemies living
            if ((self->h.quiverCount == 0) &&
                    (deadEnemyCount != (self->enemyCount - 5))) {
                for (i = 0; i < self->h.quiverMax; i++) {
                    if (self->h.w[i].offScreen == false) {
                        // there are still weapons on the screen
                        // so keep playing
                        return;
                    }
                }

                // all weapons off screen, so now play no arrows sequence
                self->h.hit = true;
            }
            break;
        case 5:
            // all butterflies are off screen OR no more arrows & all off screen

            // they are all dead and off screen
            if ((deadEnemyCount == self->enemyCount) &&
                    (offScreenEnemyCount == self->enemyCount)) {
                // go to next level
                self->mapNumber++;
                break;
            }

            // only check if we shot all of the arrows
            // and there are some enemies living
            if ((self->h.quiverCount == 0) &&
                    (deadEnemyCount != self->enemyCount)) {
                for (i = 0; i < self->h.quiverMax; i++) {
                    if (self->h.w[i].offScreen == false) {
                        // there are still weapons on the screen
                        // so keep playing
                        return;
                    }
                }

                // all weapons off screen, so now play no arrows sequence
                self->h.hit = true;
            }

            break;
        case 7:
            // slime is off screen & dead
            // arrow count doesn't matter, as long as you survive

            // they are all dead and off screen
            if (deadEnemyCount == self->enemyCount) {
                // go to next level
                self->mapNumber++;
                break;
            }

            break;
        case 9:
            // bullseye is off screen OR no more arrows & all off screen

            // they are all dead and off screen
            if (deadEnemyCount == self->enemyCount) {
                // go to next level
                self->mapNumber++;
                break;
            }

            // only check if we shot all of the arrows
            // and there are some enemies living
            if ((self->h.quiverCount == 0) &&
                    (deadEnemyCount != self->enemyCount)) {
                for (i = 0; i < self->h.quiverMax; i++) {
                    if (self->h.w[i].offScreen == false) {
                        // there are still weapons on the screen
                        // so keep playing
                        return;
                    }
                }

                // all weapons off screen, so now play no arrows sequence
                self->h.hit = true;
            }

            break;
        case 11:
            // fire is off screen & dead
            // arrow count doesn't matter, as long as you survive

            // they are all dead and off screen
            if (deadEnemyCount == self->enemyCount) {
                // go to next level
                self->mapNumber++;
                break;
            }

            break;
        case 13:
            // vultures is off screen & dead
            // arrow count doesn't matter, as long as you survive

            // take the dove off, we don't care if it's dead
            if (self->e[self->enemyCount - 1].hit == true) {
                deadEnemyCount--;
            }
            if (self->e[self->enemyCount - 1].offScreen == true) {
                offScreenEnemyCount--;
            }

            // they are all dead and off screen
            if (deadEnemyCount == (self->enemyCount - 1)) {
                // go to next level
                self->mapNumber++;
                break;
            }
            break;
        case 15:
            // wind is off screen & dead
            // arrow count doesn't matter, as long as you survive

            // they are all dead and off screen
            if (deadEnemyCount == self->enemyCount) {
                // go to next level
                self->mapNumber++;
                break;
            }
            break;
        case 17:
            // trees is off screen & dead
            // arrow count doesn't matter, as long as you survive

            // take the flame off, we don't care if it's dead
            if (self->enemyCount == 4) {
                if (self->e[self->enemyCount - 1].hit == true) {
                    deadEnemyCount--;
                }
                if (self->e[self->enemyCount - 1].offScreen == true) {
                    offScreenEnemyCount--;
                }
            }

            // they are all dead and off screen
            if (deadEnemyCount == (doveHit ? self->enemyCount : self->enemyCount - 1)) {
                // go to next level
                self->mapNumber++;
                break;
            }
            
            // only check if we shot all of the arrows
            // and there are some enemies living
            if (self->h.quiverCount == 0) {
                for (i = 0; i < self->h.quiverMax; i++) {
                    if (self->h.w[i].offScreen == false) {
                        // there are still weapons on the screen
                        // so keep playing
                        return;
                    }
                }

                // all weapons off screen, so now play no arrows sequence
                self->h.hit = true;
            }
            break;
        case 19:
            // bullseye is off screen OR no more arrows & all off screen

            // they are all dead and off screen
            if (deadEnemyCount == self->enemyCount) {
                // go to next level
                self->mapNumber++;
                break;
            }

            // only check if we shot all of the arrows
            // and there are some enemies living
            if ((self->h.quiverCount == 0) &&
                    (deadEnemyCount != self->enemyCount)) {
                for (i = 0; i < self->h.quiverMax; i++) {
                    if (self->h.w[i].offScreen == false) {
                        // there are still weapons on the screen
                        // so keep playing
                        return;
                    }
                }

                // all weapons off screen, so now play no arrows sequence
                self->h.hit = true;
            }

            break;
        case 21:
            // flashm is off screen & dead
            // arrow count doesn't matter, as long as you survive

            // they are all dead and off screen
            if (deadEnemyCount == self->enemyCount) {
                // go to next level
                self->mapNumber++;
                break;
            }
            break;
        case 23:
            // all fairies re off screen OR no more arrows & all off screen

            // delete all the watchers that are in the dead/offscreen 
            // count because we don't care if they die or not this level
            for (i = (self->enemyCount - 3); i < self->enemyCount; i++) {
                // get dead enemy & off screen count
                if (self->e[i].hit == true) {
                    deadEnemyCount--;
                }
                if (self->e[i].offScreen == true) {
                    offScreenEnemyCount--;
                }
            }

            // they are all dead (off screen to hard)
            if (deadEnemyCount == (self->enemyCount - 3)) {
                // go to next level
                self->mapNumber++;
                break;
            }

            // only check if we shot all of the arrows
            // and there are some enemies living
            if ((self->h.quiverCount == 0) &&
                    (deadEnemyCount != (self->enemyCount - 3))) {
                for (i = 0; i < self->h.quiverMax; i++) {
                    if (self->h.w[i].offScreen == false) {
                        // there are still weapons on the screen
                        // so keep playing
                        return;
                    }
                }

                // all weapons off screen, so now play no arrows sequence
                self->h.hit = true;
            }

            break;
        default:
            // nothing to do for negative/scroll levels :)
            break;
    }

}

// destruct the map
// caller frees self

static void destructMap(map *self) {
    int i;
    // free enemies
    for (i = 0; i < self->enemyCount; i++) {
        self->e[i].destructEnemy(&self->e[i]);
    }
    free(self->e);

    self->h.destructHero(&self->h);
}

/* initialize the map
 * Map numbers:
 * mapNumber % 2 = 0 correspond to maps with the scrolls, where text is printed.
 * The negative map numbers correspond to the losing message given the map
 * number as -mapNumber -1
 * 1: line of balloons
 * 3: red/yellow balloons randomly
 * 5: captured butterflies
 * 7: slimes
 * 9: bullseye
 * 11: fire
 * 13: vultures
 * 15: wind
 * 17: tree
 * 19: bullseye
 * 21: flashm
 * 23: cloud/fairy
 */
void initMap(map *self) {
    int enemyStartX;
    int enemyStartY;
    int fixHeight;
    int heroWidth;
    int screenLength;
    int i = 0;

    self->paused = false;
    self->e = NULL;
    self->quiverMax = 1;
    self->paused = false;

    self->mapNumber = mapNumber;
    self->drawMap = drawMap;
    self->updateMap = updateMap;
    self->destructMap = destructMap;

    screenLength = 7;
    fixHeight = 15;

    heroWidth = 2 * 103; // hero is 103 width


    // initialize enemy, enemy count, quiver count and enemies
    if ((self->mapNumber % 2 == 0) ||
            (self->mapNumber < 0)) { // every even number map is a scroll with text
        self->enemyCount = 1;

        self->e = malloc(sizeof (enemy) * self->enemyCount);

        enemyStartX = 43;
        enemyStartY = 30;

        initEnemy(&self->e[0], scroll, enemyStartX, enemyStartY);
    } else {
        switch (self->mapNumber) {

            case 1:
                self->quiverMax = 15;

                self->enemyCount = 15;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                enemyStartX = SCREEN_WD / 3;
                enemyStartY = SCREEN_HT;

                // put red balloons in 1 single line
                for (i = 0; i < self->enemyCount; i++) {

                    initEnemy(&self->e[i], redBalloon,
                            enemyStartX + (int) (i * balloonTRUEIMAGEW * 0.55F), enemyStartY);
                }
                break;
            case 3:
                self->quiverMax = 25;

                self->enemyCount = 20;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                // put red ballons randomly
                for (i = 0; i < self->enemyCount; i++) {
                    enemyStartX = rand() % (SCREEN_WD - 20 - heroWidth / 2) + heroWidth / 2;
                    enemyStartY = rand() % SCREEN_HT;

                    if (i < 15) {
                        initEnemy(&self->e[i], redBalloon, enemyStartX, enemyStartY);
                    } else {
                        initEnemy(&self->e[i], yellowBalloon, enemyStartX, enemyStartY);
                    }

                }
                break;
            case 5:
                self->quiverMax = 15;

                self->enemyCount = 14;

                self->e = malloc(sizeof (enemy) * self->enemyCount);
                enemyStartX = SCREEN_WD / 3;

                // put butterflys randomly
                for (i = 0; i < self->enemyCount; i++) {
                    enemyStartY = rand() % SCREEN_HT;

                    initEnemy(&self->e[i], butterfly,
                            enemyStartX + ((i-1) * butterfly_trappedTRUEIMAGEW / 2),
                            enemyStartY);
                }
                break;
            case 7:
                self->quiverMax = 30;

                self->enemyCount = 50;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                // put slimes randomly
                for (i = 0; i < self->enemyCount; i++) {
                    enemyStartX = rand() % ((screenLength * SCREEN_WD) + 1 - heroWidth) + heroWidth;
                    enemyStartY = rand() % (SCREEN_HT - slimeTRUEIMAGEH - fixHeight);

                    initEnemy(&self->e[i], slime, enemyStartX, enemyStartY);
                }
                break;
            case 9:
                self->enemyCount = 1;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                if (debug) {
                    self->quiverMax = 20;
                } else {
                    self->quiverMax = 3;
                }

                // TODO: BULLSEYE real width
                enemyStartX = SCREEN_WD - 30;
                enemyStartY = rand() % SCREEN_HT;

                // put the bullseye on screen
                initEnemy(&self->e[0], bullseye, enemyStartX, enemyStartY);
                break;
            case 11:
                self->quiverMax = 30;

                self->enemyCount = 50;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                heroWidth = 3 * 103; // 103 is hero width

                // put fires randomly
                for (i = 0; i < self->enemyCount; i++) {
                    enemyStartX = rand() % ((screenLength * SCREEN_WD) - heroWidth / 2) + heroWidth / 2;
                    enemyStartY = rand() % (SCREEN_HT - fixHeight - fire1TRUEIMAGEH);

                    initEnemy(&self->e[i], fire, enemyStartX, enemyStartY);
                }
                break;
            case 13:
                self->quiverMax = 30;

                self->enemyCount = 50;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                heroWidth = 3 * 103; // 103 is hero width

                // put vultures randomly
                for (i = 0; i < self->enemyCount - 1; i++) {
                    enemyStartX = rand() % ((screenLength * SCREEN_WD) - heroWidth / 2) + heroWidth / 2;
                    enemyStartY = rand() % (SCREEN_HT - vulture1TRUEIMAGEH - fixHeight);

                    initEnemy(&self->e[i], vulture, enemyStartX, enemyStartY);
                }

                // add the dove messenger to be on screen
                enemyStartX = SCREEN_WD;
                enemyStartY = SCREEN_HT - fixHeight;

                initEnemy(&self->e[self->enemyCount - 1], dove, enemyStartX, enemyStartY);
                break;
            case 15:
                self->quiverMax = 30;

                self->enemyCount = 50;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                heroWidth = 3 * 103; // 103 is hero width

                // put wind randomly
                for (i = 0; i < self->enemyCount; i++) {
                    enemyStartX = rand() % ((screenLength * SCREEN_WD) - heroWidth / 2) + heroWidth / 2;
                    enemyStartY = rand() % (SCREEN_HT - fixHeight - wind1TRUEIMAGEH);

                    initEnemy(&self->e[i], wind, enemyStartX, enemyStartY);
                }
                break;
            case 17:
                self->quiverMax = 20;


                self->enemyCount = (doveHit ? 3 : 4);

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                heroWidth = 3 * 103; // 103 is hero width

                enemyStartY = 5;

                // put the trees and the flame
                for (i = 0; i < 3; i++) {
                    enemyStartX = SCREEN_WD - 60;

                    initEnemy(&self->e[i], tree, enemyStartX, enemyStartY);
                    enemyStartY += SCREEN_HT / 3 + 20;

                    self->e[i].alive.state = rand() % 2;
                }

                // put the fire on the screen only if dove is not hit
                if (!doveHit) {
                    initEnemy(&self->e[self->enemyCount - 1], flame,
                            SCREEN_WD / 2, rand() % SCREEN_HT);
                }

                break;
            case 19:
                self->enemyCount = 1;

                self->quiverMax = 3;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                // TODO: BULLSEYE real width
                enemyStartX = SCREEN_WD - 30;
                enemyStartY = rand() % SCREEN_HT;

                // put the bullseye on screen
                initEnemy(&self->e[0], bullseye, enemyStartX, enemyStartY);
                break;
            case 21:
                self->quiverMax = 30;

                self->enemyCount = 50;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                heroWidth = 3 * 103; // 103 is hero width

                // put flashm randomly
                for (i = 0; i < self->enemyCount; i++) {
                    enemyStartX = rand() % ((screenLength * SCREEN_WD) - heroWidth / 2) + heroWidth / 2;
                    enemyStartY = rand() % (SCREEN_HT - flashm1TRUEIMAGEH - fixHeight);

                    initEnemy(&self->e[i], flashm, enemyStartX, enemyStartY);
                }
                break;
            case 23:
                self->quiverMax = 15;

                self->enemyCount = 12;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                heroWidth = 3 * 103; // 103 is hero width

                // put faries and watchers randomly
                for (i = 0; i < self->enemyCount; i++) {
                    enemyStartX = rand() % (SCREEN_WD - heroWidth / 2 - 20) + heroWidth / 2;
                    enemyStartY = rand() % SCREEN_HT;

                    if (i < self->enemyCount - 3) {
                        initEnemy(&self->e[i], fairy, enemyStartX, enemyStartY);
                    } else {
                        initEnemy(&self->e[i], watcher, enemyStartX, enemyStartY);
                    }

                }
                break;
            default:
                self->quiverMax = 1;

                self->enemyCount = 1;

                self->e = malloc(sizeof (enemy) * self->enemyCount);

                enemyStartX = 43;
                enemyStartY = 30;

                initEnemy(&self->e[0], flashm, enemyStartX, enemyStartY);
                break;
        }
    }

    if (self->e == NULL) {
        errors |= ERRORFLAG1;
    }

    initHero(&self->h, normal, self->quiverMax);

    // hide on scroll maps
    if (((self->mapNumber % 2) == 0) && (self->mapNumber >= 0)) {
        self->h.hidden = true;
    }

    if (self->mapNumber < 0) {
        self->h.hit = true;
    }
}

