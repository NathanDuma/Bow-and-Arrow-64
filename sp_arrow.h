#ifndef sp_arrow_h
#define sp_arrow_h

#include <PR/sp.h>

#define arrowTRUEIMAGEH	5
#define arrowTRUEIMAGEW	51
#define arrowIMAGEH	32
#define arrowIMAGEW	64
#define arrowBLOCKSIZEW	32
#define arrowBLOCKSIZEH	32
#define arrowSCALEX	1.0
#define arrowSCALEY	1.0
#define arrowMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap arrow_bitmaps[];
extern Gfx arrow_dl[];

#define NUM_arrow_BMS  (sizeof(arrow_bitmaps)/sizeof(Bitmap))

extern Sprite arrow_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
| rrrrrrrr                                       |
|                                               I|
+------------------------------------------------+
#endif

