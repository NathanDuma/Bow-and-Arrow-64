/* 
 * File:   map.c
 * Author: Nathan Duma
 *
 */

#include "map.h"


// switch map
static void switchMap(map *self, int mapNumber){
    self->destructMap(self);
    self = initMap(mapNumber);
}

static void render(map *self){
    /* Scan for User input */
    controller_scan();
    struct controller_data keys = get_keys_down();

    /* If Dpad is pressed move hero */
    if(keys.c[0].up){
        self->h->move(self->h, 'u');
    } else if(keys.c[0].down){ 
        self->h->move(self->h, 'd');	
    }
    
    /* Fill the screen */
    graphics_fill_screen(self->disp, 0x800000);
    
    /* Create Place for Text */
    char tStr[256];

    /* Text */
    if (keys.c[0].y > 0){
        graphics_draw_text(self->disp, 10, 10, "Greator");
    } else if (keys.c[0].y < 0){
        graphics_draw_text(self->disp, 10, 10, "Less");
    } else{
        graphics_draw_text(self->disp, 10, 10, "Neutral");
    }
    

    /* Update hero animation */

    self->h->playNextAnimation(self->h, &self->disp, keys.c[0].A);
    

    // debug info about hero
    sprintf(tStr, "X: %5.1f\n", self->h->v->x);
    graphics_draw_text(self->disp, 10, 20, tStr);
    sprintf(tStr, "Y: %5.1f\n", self->h->v->y);
    graphics_draw_text(self->disp, 10, 30, tStr);
    

    /* Update Display */
    display_show(self->disp);
}

// destruct the map
static void destructMap(map *self){
    for (int i = 0; i < self->enemyCount; i++){
        self->e[i].destructEnemy(&self->e[i]);
    }
    // delete self->e later
    self->h->destructHero(self->h);
    free(self);
}

// initialize the map
map *initMap(int mapNumber){
    map *self = malloc(sizeof(map));
    
    // basic map initialization
    self->disp = 0;
    self->h = initHero();
    self->mapNumber = mapNumber;
    self->render = render;
    self->switchMap = switchMap;
    self->destructMap = destructMap;
    
    // initialize enemy, enemy count, quiver count
    if (self->mapNumber == 0){
        self->quiverCount = 100;
        self->e = NULL;
        self->enemyCount = 0;
    }
    
    return self;
}



