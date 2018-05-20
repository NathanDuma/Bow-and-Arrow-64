#ifndef sp_flame_h
#define sp_flame_h

#include <PR/sp.h>

#define flameTRUEIMAGEH	32
#define flameTRUEIMAGEW	24
#define flameIMAGEH	32
#define flameIMAGEW	32
#define flameBLOCKSIZEW	32
#define flameBLOCKSIZEH	32
#define flameSCALEX	1.0
#define flameSCALEY	1.0
#define flameMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap flame_bitmaps[];
extern Gfx flame_dl[];

#define NUM_flame_BMS  (sizeof(flame_bitmaps)/sizeof(Bitmap))

extern Sprite flame_sprite;

#endif 

#if 0	/* Image preview */
+------------------------+
|            r           |
|   r        rr          |
|   rr     rrrrr         |
|   rr    rrrrrrr        |
|   rrrr rrrrrrrr        |
|   rrrrrrrrrrrrrr       |
|  rrrrrrrrrrrrrrr   rr  |
|  rrrrrrrrrrrrrrrr  rr  |
|  rrrrrrrrrYrrrrrr rrrr |
|r rrrrrrrrrYrrrrrrrrrrr |
|rrrrrrrrrrrYYrrrrrrrrrrr|
|rrrrrrrrrrrYYrrrrrrrrrrr|
|rrrrrrYrrYYYYYYrrYrrrrrr|
|rrrrrrYYrYYYYYYYYYrrrrrr|
| rrrrrYYYYYYYYYYYYrrrrrr|
| rrrrrrYYYYYCYYYYYrrrrrr|
|  rrrrrrYYYYCCYYYYrrrrr |
|  rrrrrrYYCYCCYYYYrrrrr |
|    rrrrrYYCCCYCYYrrrr  |
|     rrrrYYCbCCYYrrrrr  |
|         rYCbbCYrrrr    |
+------------------------+
#endif

