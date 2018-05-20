#ifndef sp_balloon_y_dead_h
#define sp_balloon_y_dead_h

#include <PR/sp.h>

#define balloon_y_deadTRUEIMAGEH	45
#define balloon_y_deadTRUEIMAGEW	10
#define balloon_y_deadIMAGEH	64
#define balloon_y_deadIMAGEW	32
#define balloon_y_deadBLOCKSIZEW	32
#define balloon_y_deadBLOCKSIZEH	32
#define balloon_y_deadSCALEX	1.0
#define balloon_y_deadSCALEY	1.0
#define balloon_y_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap balloon_y_dead_bitmaps[];
extern Gfx balloon_y_dead_dl[];

#define NUM_balloon_y_dead_BMS  (sizeof(balloon_y_dead_bitmaps)/sizeof(Bitmap))

extern Sprite balloon_y_dead_sprite;

#endif 

#if 0	/* Image preview */
+----------+
|          |
| YYYYYY   |
| YYYYYYY  |
|  YYYYYY  |
|   YYYYY  |
|   YYYYYY |
|  YYYYYYY |
| YYYYYYYY |
| YYYYYYYY |
| YYYYYYY  |
| YYYYYYY  |
|  YYYYYY  |
|    YYY   |
|    YY    |
|          |
|          |
|          |
|          |
|          |
|          |
+----------+
#endif

