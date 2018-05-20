#ifndef sp_arrow_fire_h
#define sp_arrow_fire_h

#include <PR/sp.h>

#define arrow_fireTRUEIMAGEH	15
#define arrow_fireTRUEIMAGEW	60
#define arrow_fireIMAGEH	32
#define arrow_fireIMAGEW	64
#define arrow_fireBLOCKSIZEW	32
#define arrow_fireBLOCKSIZEH	32
#define arrow_fireSCALEX	1.0
#define arrow_fireSCALEY	1.0
#define arrow_fireMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap arrow_fire_bitmaps[];
extern Gfx arrow_fire_dl[];

#define NUM_arrow_fire_BMS  (sizeof(arrow_fire_bitmaps)/sizeof(Bitmap))

extern Sprite arrow_fire_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                       rr                       |
|                    rrrrrrrrr  rYrYYYYrrr       |
|                      r  rrrrrrrrrrrrYY YYYYr   |
|        rrrrrrr         rrrrrrrYYYYYYYYYYrYYrYr |
|                     rrrrrrr   rrYr  rrrrY YY  I|
|        rrrrrrr        rrrrrrrrYYr rrrrrrrrYYrr |
|                  rrrrrrrrrrrrYYrrrrYYYYYYYYr   |
|                   rrrrrrrrr    rrrYYrrYrr      |
+------------------------------------------------+
#endif

