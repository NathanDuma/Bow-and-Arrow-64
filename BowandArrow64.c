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


int main(){
    /* enable interrupts (on the CPU) */
    init_interrupts();

    /* Initialize Display */
    display_init(RESOLUTION_640x480, DEPTH_32_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
   
    /* Initialize Filesystem */
    dfs_init(DFS_DEFAULT_LOCATION);
    
    /* Initialize Controller */
    controller_init();
    
    map *m = initMap(0);

    while(1){
        while(!(m->disp = display_lock()));
        m->render(m);
    }
}