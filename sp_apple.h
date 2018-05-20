#ifndef sp_apple_h
#define sp_apple_h

#include <PR/sp.h>

#define appleTRUEIMAGEH	15
#define appleTRUEIMAGEW	15
#define appleIMAGEH	32
#define appleIMAGEW	32
#define appleBLOCKSIZEW	32
#define appleBLOCKSIZEH	32
#define appleSCALEX	1.0
#define appleSCALEY	1.0
#define appleMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap apple_bitmaps[];
extern Gfx apple_dl[];

#define NUM_apple_BMS  (sizeof(apple_bitmaps)/sizeof(Bitmap))

extern Sprite apple_sprite;

#endif 

#if 0	/* Image preview */
+---------------+
|               |
|               |
|  rrrrrrrrrrrr |
| rrrrrrrrrrrrrr|
| rrrrrrrrrrrrrr|
| rrrrrrrrrrrrrr|
| rrrrrrrrrrrrrr|
| rrrrrrrrrrrrrr|
|  rrrrrrrrrrrr |
|   rrrrrrrrrr  |
+---------------+
#endif

