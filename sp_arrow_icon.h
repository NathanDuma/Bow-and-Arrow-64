#ifndef sp_arrow_icon_h
#define sp_arrow_icon_h

#include <PR/sp.h>

#define arrow_iconTRUEIMAGEH	10
#define arrow_iconTRUEIMAGEW	5
#define arrow_iconIMAGEH	32
#define arrow_iconIMAGEW	32
#define arrow_iconBLOCKSIZEW	32
#define arrow_iconBLOCKSIZEH	32
#define arrow_iconSCALEX	1.0
#define arrow_iconSCALEY	1.0
#define arrow_iconMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap arrow_icon_bitmaps[];
extern Gfx arrow_icon_dl[];

#define NUM_arrow_icon_BMS  (sizeof(arrow_icon_bitmaps)/sizeof(Bitmap))

extern Sprite arrow_icon_sprite;

#endif 

#if 0	/* Image preview */
+-----+
|Ir rI|
|Ir rI|
|Ir rI|
|II II|
|II II|
|II II|
+-----+
#endif

