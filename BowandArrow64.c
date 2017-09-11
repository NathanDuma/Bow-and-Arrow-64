/* 
 * File:   BowandArrow64.c
 * Author: Nathan Duma
 *
 */

#include "debug.h"
#include "BowandArrow64.h"
#include "map.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include <stdlib.h>
#include <time.h>


int main(){
    /* enable interrupts (on the CPU) */
    init_interrupts();

    /* Initialize Display */
    display_init(RESOLUTION_640x480, DEPTH_32_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
   
    /* Initialize Filesystem */
    dfs_init(DFS_DEFAULT_LOCATION);
    
    /* Initialize Controller */
    controller_init();
    
    // init debug text
    startDebugX = 0;
    startDebugY = 0;
    debug = true; // set this true if you want debug messages!!
    
    // init RNG
    srand(time(NULL));
    
    // start map is 0
    int currentMap = 0;
    
    disp = malloc(sizeof(display_context_t));
    *disp = 0;
    
    map *m = initMap(currentMap);

    while(1){
        
        currentMap = m->render(m);
        
        // display the contents of the map
        display_show(*m->disp);
        
        
        // switch maps if needed
        if (currentMap != m->mapNumber){
            m->destructMap(m);
            free(m);
            m = initMap(currentMap);
            printDebugMessage("END ------------------------");
        }
        
        startDebugX = 0;
        startDebugY = 0;
    }
    // never reached
    m->destructMap(m);
    free(m);
}