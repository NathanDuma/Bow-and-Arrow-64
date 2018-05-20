#ifndef sp_tree_dead_h
#define sp_tree_dead_h

#include <PR/sp.h>

#define tree_deadTRUEIMAGEH	72
#define tree_deadTRUEIMAGEW	72
#define tree_deadIMAGEH	96
#define tree_deadIMAGEW	96
#define tree_deadBLOCKSIZEW	32
#define tree_deadBLOCKSIZEH	32
#define tree_deadSCALEX	1.0
#define tree_deadSCALEY	1.0
#define tree_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap tree_dead_bitmaps[];
extern Gfx tree_dead_dl[];

#define NUM_tree_dead_BMS  (sizeof(tree_dead_bitmaps)/sizeof(Bitmap))

extern Sprite tree_dead_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|                  i       rr                    |
|                   i      @r                    |
|                   i   i  Yr                    |
|                   ii  i rr                     |
|                    i@ i rr                     |
|                    ii i Yr                     |
|                     i iiY                      |
|                       @@r                      |
|                     i ii                       |
|                      @ii                       |
|                      @ii                       |
|           rrr         @i              i i      |
|           rrr        @@             i i        |
|           rYr        @@ i      ii    i         |
|            Yr         @ i                      |
|           ir ii i       i                      |
|       ii                i                      |
|    ii                   i                      |
|                        ii                      |
|                         i                      |
|                        @i                      |
|                         i                      |
|                      i  i                      |
|                      i @i i                    |
|                      i  ii i                   |
|                          i  i                  |
|                    ii        i                 |
|                  @i   i    i@                  |
|                 i           ii                 |
|                                iii             |
|                                  iii           |
+------------------------------------------------+
#endif

