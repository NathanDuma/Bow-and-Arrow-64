#ifndef sp_balloon_h
#define sp_balloon_h

#include <PR/sp.h>

#define balloonTRUEIMAGEH	39
#define balloonTRUEIMAGEW	25
#define balloonIMAGEH	64
#define balloonIMAGEW	32
#define balloonBLOCKSIZEW	32
#define balloonBLOCKSIZEH	32
#define balloonSCALEX	1.0
#define balloonSCALEY	1.0
#define balloonMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap balloon_bitmaps[];
extern Gfx balloon_dl[];

#define NUM_balloon_BMS  (sizeof(balloon_bitmaps)/sizeof(Bitmap))

extern Sprite balloon_sprite;

#endif 

#if 0	/* Image preview */
+-------------------------+
|                         |
|         rrrrrrr         |
|     rrrrrrrrrrrrrrr     |
|   rrrrrrrrrrrrrrrrrrr   |
|  rrrrrrrrrrrrrrrrrrrrr  |
|  rrrrrrrrrrrrrrrrrrrrr  |
| rrrrrrrrrrrrrrrrrrrrrrr |
| rrrrrrrrrrrrrrrrrrrrrrr |
| rrrrrrrrrrrrrrrrrrrrrrr |
| rrrrrrrrrrrrrrrrrrrrrrr |
|  rrrrrrrrrrrrrrrrrrrrr  |
|   rrrrrrrrrrrrrrrrrrr   |
|     rrrrrrrrrrrrrrr     |
|      rrrrrrrrrrrrr      |
|        rrrrrrrr         |
|         rrrrrr          |
|            r            |
|                         |
|                         |
|                         |
|                         |
|                         |
|                         |
|                         |
|                         |
|                         |
+-------------------------+
#endif

