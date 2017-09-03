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
    int currentMap = 0;
    srand(time(NULL));
    
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
        }
        
        
    }
}