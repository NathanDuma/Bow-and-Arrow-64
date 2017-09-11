/* 
 * File:   map.c
 * Author: Nathan Duma
 *
 */

#include "map.h"


// get any button press from the controller
static bool anyKey(struct controller_data *keys){
    return keys->c[0].A || keys->c[0].B || keys->c[0].C_up || keys->c[0].C_down ||
           keys->c[0].C_left || keys->c[0].C_right || keys->c[0].L || 
           keys->c[0].R || keys->c[0].Z;
}


// render the map every frame
static int render(map *self){
    while(!(*self->disp = display_lock()));
    
    // fill screen with green
    graphics_fill_screen(*self->disp, 0x800000);
    
    // scan the user input
    controller_scan();
    struct controller_data keys = get_keys_pressed();
    
    // we are printing the scroll text now
    if (self->mapNumber % 2 == 0){
        // show the scroll animation
        for (llist *itEnemy = self->e; itEnemy; itEnemy = itEnemy->next){
            ((enemy*)itEnemy->node)->playNextAnimation(((enemy*)itEnemy->node), self->disp);
        }
        // show the dead hero animation if we are on a dead screen
        // only show this for maps where you can get hit (no balloons or bullseye map)
        if (self->mapNumber < -4 && self->mapNumber != -8){
            self->h->hit = true;

            self->h->v->x = 0.0;
            self->h->v->y = SCREENHEIGHT/2;
            
            self->h->playNextAnimation(self->h, self->disp, false);
        }
        
        int textStartX = SCREENWIDTH/2 - 103;
        int textStartY = SCREENHEIGHT/2 - 70;
        
        graphics_set_color(0x00000001, 0x00000000);
        
        if (self->mapNumber == -18){
            printMessage("\t    ---ZAP---\n\n\n\n"
                         " Watch out for the GUARDIANS\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        } else if (self->mapNumber == -16){
            printMessage("\n\n\n\n"
                         " Yeow, they're HOT!!!\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        } else if (self->mapNumber == -14){
            printMessage("\n\n\n\n"
                         "  You can't make apple sauce\n"
                         "  with those apples!\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        } else if (self->mapNumber == -12){
            printMessage("\n\n\n\n    "
                         "Don't loose your head!\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        } else if (self->mapNumber == -10){
            printMessage("\n\n\n\n\n\t\tOUCH!\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        } else if (self->mapNumber == -8){
            printMessage("\n\n\n\n"
                         "You'll have to shoot\n"
                         "better than that to continue\n"
                         "this Quest..\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        } else if (self->mapNumber == -6){
            printMessage("\n\n\n\n"
                         "You've been Slimed...\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        } else if (self->mapNumber == -4){
            printMessage("  What is an archer without\n"
                         "  his arrows? He doesn't\n"
                         "  continue in this game.\n\n\n"
                         "\t\tThe end",
                         textStartX, textStartY);
        } else if (self->mapNumber == -2){
            printMessage("  What is an archer without\n"
                         "  his arrows? He doesn't\n"
                         "  continue in this game.\n\n\n"
                         "\t\tThe end",
                         textStartX, textStartY);
        } else if (self->mapNumber == 0){
            printMessage("\t Target Practice\n\n"
                         "Our journey begins on the\n"
                         "target range. Target\n"
                         "launchers release balloons\n"
                         "up range for the archers to\n"
                         "shoot. Your task - Shoot all\n"
                         "of the balloons.\n\n\n"
                         "This is a remake of the\n"
                         "original Bow and Arrow\n"
                         "game for Windows 95. Enjoy!\n\n\n"
                         "\tMade by:\n"
                         "\tNathan Duma\n\n\n" 
                         "Press any button to play...",
                         textStartX, textStartY);
        } else if (self->mapNumber == 2){
            printMessage("\tMore Target Practice\n\n"
                         "Nice shooting! The only way\n"
                         "to become a great archer is\n"
                         "to practice. After all,\n"
                         "practice makes perfect.\n"
                         "Now it gets a little tougher.\n"
                         "Only shoot the RED balloons.",
                         textStartX, textStartY);
        } else if (self->mapNumber == 4){
            printMessage("\t  Bouncing Bubbles\n\n"
                         "Having had enough target\n"
                         "practice for one day, you\n"
                         "take a walk. In a small glade\n"
                         "you spy a number of\n"
                         "butterflies imprisoned by\n"
                         "bubbles. Taking pity on the\n"
                         "little creatures, you decide\n"
                         "to free them...",
                         textStartX, textStartY);
        } else if (self->mapNumber == 6){
            printMessage("\t\t  SLIMED\n\n"
                         "The greatful butterflies tell\n"
                         "of an evil imprisonment spell\n"
                         "cast by The Black Archer, The\n"
                         "greatest archer in all the\n"
                         "Land! Greatest? Hah! you\n"
                         "snicker. The Quest begins.\n"
                         "In your path: the SWAMP...",
                         textStartX, textStartY);
        } else if (self->mapNumber == 8){
            printMessage("\t\tBulls Eye\n\n"
                         "As the Quest proceeds you\n"
                         "will be tested for speed, \n"
                         "cunning, and accuracy. The\n"
                         "tests begin! You Need a\n"
                         "Bull's Eye to Continue...",
                         textStartX, textStartY);
        } else if (self->mapNumber == 10){
            printMessage("\t\tFIREBALLS\n\n"
                         "Nice Shot! Suddenly you hear\n"
                         "an earth shattering raport.\n"
                         "The hillside nearest you\n"
                         "explodes into thousands of\n"
                         "flaming lava rocks, many of\n"
                         "which are heading straight\n"
                         "for you. No time to seek\n"
                         "shelter...",
                         textStartX, textStartY);
        } else if (self->mapNumber == 12){
            printMessage("\t  Unfriendly Skies\n\n"
                         "Thinking those rocks may have\n"
                         "been meant for you, you\n"
                         "decide to send a message to\n"
                         "your friendKhanin the Wizard.\n"
                         "A passing dove agrees to\n"
                         "deliver your message. Just\n"
                         "then the skies went BLACK...",
                         textStartX, textStartY);
        } else if (self->mapNumber == 14){
            printMessage("\t   Whrrrrrrrrrr\n\n"
                         "The Black Archer is\n"
                         "definitely on to you. His\n"
                         "servants are everywhere and\n"
                         "will stop at nothing in an\n"
                         "effort terminate your\n"
                         "existence. From beyond sight,\n"
                         "you hear a strange whirring\n"
                         "noise...",
                         textStartX, textStartY);
        } else if (self->mapNumber == 16){
            printMessage("\t   Dark Forest\n\n"
                         "As you wind your way along\n"
                         "the path unseen eyes are\n"
                         "glaring at you. When you\n"
                         "reach the edge of a line of\n"
                         "trees you are in for nothing\n"
                         "but trouble... I hope the\n"
                         "Message got through to\n"
                         "Khanin.",
                         textStartX, textStartY);
        } else if (self->mapNumber == 18){
            printMessage("Wow! You made it to the end!\n"
                         "Thank you for playing!\n\n\n"
                         "\t\tThe end.",
                         textStartX, textStartY);
        }
        graphics_set_color(0xFFFFFFFF, 0x00000000); // reset colours

        if (anyKey(&keys)){ // press any key to go to the next level
            if (self->mapNumber < 0 || self->mapNumber == 18) return 0; // any failure maps go back to the beginning
            return self->mapNumber + 1;
        } else{
            return self->mapNumber;
        }
        
    } else{ // we are rending the gameplay
        // move hero
        if(keys.c[0].up || keys.c[0].y > 0){
            self->h->move(self->h, up);
        } else if(keys.c[0].down || keys.c[0].y < 0){ 
            self->h->move(self->h, down);	
        }
        
        if (keys.c[0].start && !self->paused){
            self->paused = true;
        } else if (keys.c[0].start && self->paused){
            self->paused = false;
        }
        
        if (self->paused){
            printMessage("PAUSED", SCREENWIDTH/2, SCREENHEIGHT/2);
            return self->mapNumber;
        }
   
        // check collison between enemies and quiver
        for (int i = 0; i < self->enemyCount; i++){
        for (llist *itEnemy = self->e; itEnemy; itEnemy = itEnemy->next){
            for (int j = 0; j < self->quiverMax; j++){
                if (!((enemy*)itEnemy->node)->hit && !((enemy*)itEnemy->node)->offScreen){
                    ((enemy*)itEnemy->node)->checkCollison(itEnemy->node, self->h->w[j], self->h);
                } 
            }
        }
        }

        // update hero animation
        self->h->playNextAnimation(self->h, self->disp, anyKey(&keys));

        int offScreenQuiverCount = 0;

        // draw all of the weapons on screen
        for (int i = 0; i < self->quiverMax; i++){
            if (self->h->w[i]->shot && !self->h->w[i]->offScreen)
                self->h->w[i]->playNextAnimation(self->h->w[i], self->disp);
            if (self->h->w[i]->offScreen && self->h->w[i]->shot) offScreenQuiverCount++;
        }


        int offScreenEnemyCount = 0;
        int deadEnemyCount = 0;
        
        // draw all enemies on the screen
        for (llist *itEnemy = self->e; itEnemy; itEnemy = itEnemy->next){
            ((enemy*)itEnemy->node)->playNextAnimation(((enemy*)itEnemy->node), self->disp);
            if (((enemy*)itEnemy->node)->offScreen) offScreenEnemyCount++;
            if (((enemy*)itEnemy->node)->hit) deadEnemyCount++;
        }

        
        // buffer for messages
        char tStr[256];
        // debug info about hero
        sprintf(tStr, "Hero x: %5.1f\n", self->h->v->x);
        graphics_draw_text(*self->disp, 375, 0, tStr);
        sprintf(tStr, "Hero y: %5.1f\n", self->h->v->y);
        graphics_draw_text(*self->disp, 375, 10, tStr);
        
        
        sprintf(tStr, "Arrows left: %i\n", self->h->quiverCount);
        graphics_draw_text(*self->disp, 500, 0, tStr);
        
        sprintf(tStr, "Enemies left: %i\n", self->enemyCount - deadEnemyCount);
        graphics_draw_text(*self->disp, 500, 10, tStr);

        // check if the player can progress maps or if they lost
        if (offScreenEnemyCount == self->enemyCount){ // all enemies are dead
            return self->mapNumber + 1; // progress
        } else if (self->h->hit || (offScreenQuiverCount == self->quiverMax &&
                   deadEnemyCount != self->enemyCount && 
                (self->mapNumber != 7 && self->mapNumber < 10))){ // no more quiver, enemies still on screen
            if (self->mapNumber == 1) return -2;
            return -1 * self->mapNumber + 1;
        } else{
            return self->mapNumber; // not done yet
        }
    }
}

// destruct the map
// caller frees self
static void destructMap(map *self){
    // free enemies
    printDebugMessage("destructMap");
    
    printDebugMessage("Calling destructEnemy(self->e[i])");
    for (llist *itEnemy = self->e; itEnemy; itEnemy = itEnemy->next){
        ((enemy*)itEnemy->node)->destructEnemy(itEnemy->node);
    }
    printDebugMessage("Freed self->e[i]");
    
    printDebugMessage("Freeing self->e");
    destructllist(self->e);
    printDebugMessage("Freed self->e");
    
    // free hero
    printDebugMessage("Calling destructHero");
    self->h->destructHero(self->h, self->quiverMax);
    printDebugMessage("Freed hero");
    
    printDebugMessage("Freeing s->h");
    free(self->h);
    printDebugMessage("Freed self->h");
    
/*
    // free the display
    printDebugMessage("Freeing self->disp");
    free(self->disp);
*/
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
 * 15: vultures (TODO: add this level and sprites)
 * 17: random? (TODO: add this level and the sprites)
 */
map *initMap(int mapNumber){
    map *self = (map*)malloc(sizeof(map));
    
    if (!self) printDebugMessage("Failed to allocate map *self");
    
    self->disp = disp;
    
/*
    // basic map initialization
    self->disp = (display_context_t*)malloc(sizeof(display_context_t));
    *self->disp = 0;
    // update the debug display
    disp = self->disp;
*/
    
    self->e = NULL;
    
    if (!self->disp) printDebugMessage("Failed to allocate self->disp");
    
    self->paused = false;
    
    self->mapNumber = mapNumber;
    self->render = render;
    self->destructMap = destructMap;
    
    self->e = NULL;
    
    // initialize enemy, enemy count, quiver count and enemies
    if (self->mapNumber % 2 == 0){ // every even number map is a scroll with text
        self->enemyCount = 1;
        
        int enemyStartX = SCREENWIDTH/2 - 133;
        int enemyStartY = SCREENHEIGHT/2 - 110;
        
        self->e = addllist(self->e, initEnemy(scroll));
        ((enemy*)self->e->node)->initLocation(self->e->node, enemyStartX, enemyStartY);

    } else if (self->mapNumber == 1){
        self->quiverMax = 15;

        self->enemyCount = 15;
        
        int enemyStartX = 230;
        int enemyStartY = SCREENHEIGHT;
        
        // put red balloons in 1 single line
        for (int i = 0; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(redBalloon));
            ((enemy*)self->e->node)->initLocation(self->e->node, 
               enemyStartX + (i * ((enemy*)self->e->node)->alive->a[0]->width), enemyStartY);
        }
    } else if (self->mapNumber == 3){
        self->quiverMax = 25;

        self->enemyCount = 20;
        
        int heroWidth = 2 * 103; // the hero is 103 pixels wide

        // put red ballons randomly
        for (int i = 0; i < self->enemyCount-5; i++){
            self->e = addllist(self->e, initEnemy(redBalloon));
            ((enemy*)self->e->node)->initLocation(self->e->node,
                rand() % (SCREENWIDTH + 1 - heroWidth) + heroWidth,
                rand() * SCREENHEIGHT);
        }
        // put yellow balloons randomly
        for (int i = self->enemyCount-5; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(yellowBalloon));
            ((enemy*)self->e->node)->initLocation(self->e->node,
                rand() % (SCREENWIDTH + 1 - heroWidth) + heroWidth,
                rand() % SCREENHEIGHT);
        }
    } else if (self->mapNumber == 5){
        self->quiverMax = 50;

        self->enemyCount = 30;
        
        int heroWidth = 2 * 103; // hero is 103 width

        // put butterflys randomly
        for (int i = 0; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(butterfly));
            ((enemy*)self->e->node)->initLocation(self->e->node,
                rand() % (SCREENWIDTH + 1 - heroWidth) + heroWidth,
                rand() % SCREENHEIGHT);
        }
    } else if (self->mapNumber == 7){
        self->quiverMax = 100;

        self->enemyCount = 50;
        
        int heroWidth = 3 * 103; // 103 is hero width
        int screenLength = 6; // how many "screens" over the farthest enemy can be

        // put slimes randomly
        for (int i = 0; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(slime));
            ((enemy*)self->e->node)->initLocation(self->e->node,
                rand() % ((screenLength * SCREENWIDTH) + 1 - heroWidth) + heroWidth,
                rand() % (SCREENHEIGHT - 80));
        }
    } else if (self->mapNumber == 9){
        self->enemyCount = 1;
        
        self->quiverMax = 10;
                
        // put the bullseye on screen
        self->e = addllist(self->e, initEnemy(bullseye));
        
        int enemyStartX = SCREENWIDTH - 4 * ((enemy*)self->e->node)->alive->a[0]->width;
        int enemyStartY = rand() % (SCREENHEIGHT - 80);
        
        ((enemy*)self->e->node)->initLocation(self->e->node,
                                              enemyStartX, enemyStartY);
    } else if (self->mapNumber == 11){
        self->quiverMax = 100;

        self->enemyCount = 50;
        
        int heroWidth = 3 * 103; // 103 is hero width
        int screenLength = 6; // how many screens over the fires can be

        // put fires randomly
        for (int i = 0; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(fire));
            ((enemy*)self->e->node)->initLocation(self->e->node,
            rand() % ((screenLength * SCREENWIDTH) + 1 - heroWidth) + heroWidth,
            rand() % (SCREENHEIGHT - 80));
        }
    } else if (self->mapNumber == 13){
        self->quiverMax = 100;

        self->enemyCount = 50;
        
        int heroWidth = 3 * 103; // 103 is hero width
        int screenLength = 6; // 6 screens over the vultures can be

        // put vultures randomly
        for (int i = 0; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(vulture));
            ((enemy*)self->e->node)->initLocation(self->e->node,
            rand() % ((screenLength * SCREENWIDTH) + 1 - heroWidth) + heroWidth,
            rand() % (SCREENHEIGHT - 80));
        }
        
        // add the dove messenger to be on screen
        // TODO: put it in the location
        self->e = addllist(self->e, initEnemy(dove));
        ((enemy*)self->e->node)->initLocation(self->e->node, 100, 100);
        
    } else if (self->mapNumber == 15){
        self->quiverMax = 100;

        self->enemyCount = 50;
        
        int heroWidth = 3 * 103; // 103 is hero width
        int screenLength = 6; // 6 screens

        // put vultures randomly
        for (int i = 0; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(vulture));
            ((enemy*)self->e->node)->initLocation(self->e->node,
                rand() % ((screenLength * SCREENWIDTH) + 1 - heroWidth) + heroWidth,
                rand() % (SCREENHEIGHT - 80));
        }
    } else if (self->mapNumber == 17){
        self->quiverMax = 100;

        self->enemyCount = 50;
        
        int heroWidth = 3 * 103; // 103 is hero width
        int screenLength = 6; // 6 screens
        
        // put fire, slime, vulture, wind in this array to choose randomly
        //const int randomEnemy[4] = {3, 4, 5, 6};

        // put enemies randomly
        for (int i = 0; i < self->enemyCount; i++){
            self->e = addllist(self->e, initEnemy(vulture));
            ((enemy*)self->e->node)->initLocation(self->e->node,
                rand() % ((screenLength * SCREENWIDTH) + 1 - heroWidth) + heroWidth,
                rand() % (SCREENHEIGHT - 80));
        }
    }
/*
    else if (self->mapNumber == 25){ // test map
        self->quiverMax = 10;

        self->enemyCount = 1;
        
        self->e = (enemy**)malloc(sizeof(enemy*) * self->enemyCount);
        int enemyStartX = SCREENWIDTH/2 - 133;
        int enemyStartY = SCREENHEIGHT/2 - 110;
        
        const int randomEnemy[4] = {1, 2, 3, 4};

        // put enemies randomly
        for (int i = 0; i < 41; i++){
            self->ee = addllist(self->ee, initEnemy(randomEnemy[rand() % 4]));
            ((enemy*)self->ee->node)->initLocation(self->ee->node, 
            rand() % SCREENWIDTH,
            rand() % (SCREENHEIGHT - 80));
        }
        
        
        self->e[0] = initEnemy(redBalloon);
        self->e[0]->initLocation(self->e[0], enemyStartX, enemyStartY);
        
    }
    
*/
    self->h = initHero(normal, self->quiverMax);
    
    return self;
}

