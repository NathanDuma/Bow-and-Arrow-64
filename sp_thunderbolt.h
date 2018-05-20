#ifndef sp_thunderbolt_h
#define sp_thunderbolt_h

#include <PR/sp.h>

#define thunderboltTRUEIMAGEH	10
#define thunderboltTRUEIMAGEW	58
#define thunderboltIMAGEH	32
#define thunderboltIMAGEW	64
#define thunderboltBLOCKSIZEW	32
#define thunderboltBLOCKSIZEH	32
#define thunderboltSCALEX	1.0
#define thunderboltSCALEY	1.0
#define thunderboltMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap thunderbolt_bitmaps[];
extern Gfx thunderbolt_dl[];

#define NUM_thunderbolt_BMS  (sizeof(thunderbolt_bitmaps)/sizeof(Bitmap))

extern Sprite thunderbolt_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                     YYYYYYYYYY                 |
|YYYYYYYYYYYYYYYYYYYYYYYYYYYYY                   |
|              YYYYYYYYYYYYYY                    |
|                    YYYYYYYYYYYYYYYYYYYYYYYYYYYY|
|                   YYYYYYYYYYYYYYYYYYYYYYYYYYYY |
+------------------------------------------------+
#endif

