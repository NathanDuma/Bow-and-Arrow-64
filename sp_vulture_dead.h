#ifndef sp_vulture_dead_h
#define sp_vulture_dead_h

#include <PR/sp.h>

#define vulture_deadTRUEIMAGEH	51
#define vulture_deadTRUEIMAGEW	55
#define vulture_deadIMAGEH	64
#define vulture_deadIMAGEW	64
#define vulture_deadBLOCKSIZEW	32
#define vulture_deadBLOCKSIZEH	32
#define vulture_deadSCALEX	1.0
#define vulture_deadSCALEY	1.0
#define vulture_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap vulture_dead_bitmaps[];
extern Gfx vulture_dead_dl[];

#define NUM_vulture_dead_BMS  (sizeof(vulture_dead_bitmaps)/sizeof(Bitmap))

extern Sprite vulture_dead_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                             i                  |
|                            i i                 |
|             i iii                              |
|             i             i     i              |
|             i        i                         |
|             i         i           i            |
|                        i i        i            |
|                          i         i           |
|              i          i          i           |
|                         i                      |
|                                     i          |
|               i                     i          |
|                i       i             i         |
|                i       i             i         |
|                        i                       |
|                       i              i         |
|                 i     i              i         |
|                 i    i               i         |
|                 i                    i         |
|        iiii      i  i               i          |
|        r@@  i    i                             |
|  yyyyy r@@ @     iii                i          |
| Y   yy  @@@@i    i@                            |
|   y     i @ @ @@@                           i i|
|            i@@@@i i                           i|
|             i i @i                            i|
|rrrrrrr          i                    iii      i|
|rrrrrrr            i               y yyy  i   i |
|                      i iii iiii     y yy       |
+------------------------------------------------+
#endif

