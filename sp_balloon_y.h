#ifndef sp_balloon_y_h
#define sp_balloon_y_h

#include <PR/sp.h>

#define balloon_yTRUEIMAGEH	39
#define balloon_yTRUEIMAGEW	25
#define balloon_yIMAGEH	64
#define balloon_yIMAGEW	32
#define balloon_yBLOCKSIZEW	32
#define balloon_yBLOCKSIZEH	32
#define balloon_ySCALEX	1.0
#define balloon_ySCALEY	1.0
#define balloon_yMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap balloon_y_bitmaps[];
extern Gfx balloon_y_dl[];

#define NUM_balloon_y_BMS  (sizeof(balloon_y_bitmaps)/sizeof(Bitmap))

extern Sprite balloon_y_sprite;

#endif 

#if 0	/* Image preview */
+-------------------------+
|                         |
|         YYYYYYY         |
|     YYYYYYYYYYYYYYY     |
|   YYYYYYYYYYYYYYYYYYY   |
|  YYYYYYYYYYYYYYYYYYYYY  |
|  YYYYYYYYYYYYYYYYYYYYY  |
| YYYYYYYYYYYYYYYYYYYYYYY |
| YYYYYYYYYYYYYYYYYYYYYYY |
| YYYYYYYYYYYYYYYYYYYYYYY |
| YYYYYYYYYYYYYYYYYYYYYYY |
|  YYYYYYYYYYYYYYYYYYYYY  |
|   YYYYYYYYYYYYYYYYYYY   |
|     YYYYYYYYYYYYYYY     |
|      YYYYYYYYYYYYY      |
|        YYYYYYYY         |
|         YYYYYY          |
|            Y            |
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

