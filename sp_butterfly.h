#ifndef sp_butterfly_h
#define sp_butterfly_h

#include <PR/sp.h>

#define butterflyTRUEIMAGEH	19
#define butterflyTRUEIMAGEW	18
#define butterflyIMAGEH	32
#define butterflyIMAGEW	32
#define butterflyBLOCKSIZEW	32
#define butterflyBLOCKSIZEH	32
#define butterflySCALEX	1.0
#define butterflySCALEY	1.0
#define butterflyMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap butterfly_bitmaps[];
extern Gfx butterfly_dl[];

#define NUM_butterfly_BMS  (sizeof(butterfly_bitmaps)/sizeof(Bitmap))

extern Sprite butterfly_sprite;

#endif 

#if 0	/* Image preview */
+------------------+
|                  |
|               Y  |
|            rYrYr |
|           rY YrY |
|         rYrY Yr  |
|         YrYrYrY  |
|        r  YrYrY  |
|         YrYr  Yr |
|          YrY  rY |
|            YrYrY |
|                  |
|                  |
+------------------+
#endif

