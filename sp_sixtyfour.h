#ifndef sp_sixtyfour_h
#define sp_sixtyfour_h

#include <PR/sp.h>

#define sixtyfourTRUEIMAGEH	17
#define sixtyfourTRUEIMAGEW	23
#define sixtyfourIMAGEH	32
#define sixtyfourIMAGEW	32
#define sixtyfourBLOCKSIZEW	32
#define sixtyfourBLOCKSIZEH	32
#define sixtyfourSCALEX	1.0
#define sixtyfourSCALEY	1.0
#define sixtyfourMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap sixtyfour_bitmaps[];
extern Gfx sixtyfour_dl[];

#define NUM_sixtyfour_BMS  (sizeof(sixtyfour_bitmaps)/sizeof(Bitmap))

extern Sprite sixtyfour_sprite;

#endif 

#if 0	/* Image preview */
+-----------------------+
|                       |
|                       |
|    rrrrr.      rrrrr  |
|   rrrrrr      rrrrrr  |
| .rrr .       rrRRrrr  |
| rrrrrrrr    rrrIRrrr  |
| rrrRIIrrrr rrrRrrrrrr |
| rrrRIIRrrr rrrrrrrrrr |
| rrrrRRrrr. .....rrrr. |
|  rrrrrrrr       rrrr  |
|    rrrr         .rr.  |
+-----------------------+
#endif

