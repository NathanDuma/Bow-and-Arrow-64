#ifndef sp_balloon_dead_h
#define sp_balloon_dead_h

#include <PR/sp.h>

#define balloon_deadTRUEIMAGEH	45
#define balloon_deadTRUEIMAGEW	10
#define balloon_deadIMAGEH	64
#define balloon_deadIMAGEW	32
#define balloon_deadBLOCKSIZEW	32
#define balloon_deadBLOCKSIZEH	32
#define balloon_deadSCALEX	1.0
#define balloon_deadSCALEY	1.0
#define balloon_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap balloon_dead_bitmaps[];
extern Gfx balloon_dead_dl[];

#define NUM_balloon_dead_BMS  (sizeof(balloon_dead_bitmaps)/sizeof(Bitmap))

extern Sprite balloon_dead_sprite;

#endif 

#if 0	/* Image preview */
+----------+
|          |
| rrrrrr   |
| rrrrrrr  |
|  rrrrrr  |
|   rrrrr  |
|   rrrrrr |
|  rrrrrrr |
| rrrrrrrr |
| rrrrrrrr |
| rrrrrrr  |
| rrrrrrr  |
|  rrrrrr  |
|    rrr   |
|    rr    |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
#endif

