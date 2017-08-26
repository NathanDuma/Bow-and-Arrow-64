/* 
 * File:   BowandArrow64.c
 * Author: Nathan Duma
 *
 */

#include "BowandArrow64.h"
#include "map.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include <stdlib.h>

typedef struct{
   float x;
   float y;
} lel;


int main(){
    /* enable interrupts (on the CPU) */
    init_interrupts();

    /* Initialize Display */
    display_init(RESOLUTION_640x480, DEPTH_32_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
   
    /* Initialize Filesystem */
    dfs_init(DFS_DEFAULT_LOCATION);
    
    /* Initialize Controller */
    controller_init();
    
    /* Read in single sprite */
    int fp = dfs_open("/scroll.sprite"); 
    sprite_t *n64f = malloc(dfs_size(fp));
    dfs_read(n64f, 1, dfs_size(fp), fp);
    dfs_close(fp);
    
    map *m = initMap(0);
    
    lel *l = malloc(sizeof(lel));
    
    
    l->x = 0.0;
    

    /* Main loop test */ 
    while(1){
        /* Grab a render buffer */
        while(!(m->disp = display_lock()));
        
        m->render(m);
        
    }
}