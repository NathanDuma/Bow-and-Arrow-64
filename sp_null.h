#ifndef sp_null_h
#define sp_null_h

#include <PR/sp.h>

#define nullTRUEIMAGEH	1
#define nullTRUEIMAGEW	1
#define nullIMAGEH	32
#define nullIMAGEW	32
#define nullBLOCKSIZEW	32
#define nullBLOCKSIZEH	32
#define nullSCALEX	1.0
#define nullSCALEY	1.0
#define nullMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap null_bitmaps[];
extern Gfx null_dl[];

#define NUM_null_BMS  (sizeof(null_bitmaps)/sizeof(Bitmap))

extern Sprite null_sprite;

#endif 

#if 0	/* Image preview */
+-+
+-+
#endif

