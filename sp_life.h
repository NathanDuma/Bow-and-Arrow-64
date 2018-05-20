#ifndef sp_life_h
#define sp_life_h

#include <PR/sp.h>

#define lifeTRUEIMAGEH	9
#define lifeTRUEIMAGEW	12
#define lifeIMAGEH	32
#define lifeIMAGEW	32
#define lifeBLOCKSIZEW	32
#define lifeBLOCKSIZEH	32
#define lifeSCALEX	1.0
#define lifeSCALEY	1.0
#define lifeMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap life_bitmaps[];
extern Gfx life_dl[];

#define NUM_life_BMS  (sizeof(life_bitmaps)/sizeof(Bitmap))

extern Sprite life_sprite;

#endif 

#if 0	/* Image preview */
+------------+
| rrIIIIIIIII|
|r  rrIIIIIII|
|IIrr rrrrIII|
|IIIrr  rrrII|
|IIIIIrrr rrI|
|IIIIIIIrr  I|
+------------+
#endif

