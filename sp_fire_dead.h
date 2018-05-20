#ifndef sp_fire_dead_h
#define sp_fire_dead_h

#include <PR/sp.h>

#define fire_deadTRUEIMAGEH	20
#define fire_deadTRUEIMAGEW	52
#define fire_deadIMAGEH	32
#define fire_deadIMAGEW	64
#define fire_deadBLOCKSIZEW	32
#define fire_deadBLOCKSIZEH	32
#define fire_deadSCALEX	1.0
#define fire_deadSCALEY	1.0
#define fire_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap fire_dead_bitmaps[];
extern Gfx fire_dead_dl[];

#define NUM_fire_dead_BMS  (sizeof(fire_dead_bitmaps)/sizeof(Bitmap))

extern Sprite fire_dead_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|        y yr                                    |
|             y        YY            Y Y YYYY    |
|               y y      rrrYYYYYY rrY           |
|   y            yr    rrrgYgYYYYY   rr    rrrrrr|
| y                      rrrrrrr rrrrr           |
| y              y       rrgrrr      YYYY YY rrr |
|                y     rrrrrrYYYYY rrrYr r       |
|  y   y               rrrYrrrrrrY  YY Y         |
|             y        rrrrrrr Yrr Y Y YY        |
|     y   y  y       Y Yrrr    YYY YYY           |
|         y y         YYYY YYYYY                 |
+------------------------------------------------+
#endif

