#ifndef sp_nintendologo_h
#define sp_nintendologo_h

#include <PR/sp.h>

#define nintendologoTRUEIMAGEH	29
#define nintendologoTRUEIMAGEW	130
#define nintendologoIMAGEH	32
#define nintendologoIMAGEW	160
#define nintendologoBLOCKSIZEW	32
#define nintendologoBLOCKSIZEH	32
#define nintendologoSCALEX	1.0
#define nintendologoSCALEY	1.0
#define nintendologoMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap nintendologo_bitmaps[];
extern Gfx nintendologo_dl[];

#define NUM_nintendologo_BMS  (sizeof(nintendologo_bitmaps)/sizeof(Bitmap))

extern Sprite nintendologo_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|                                                |
|  bbb.b.bbb bbb b bbbbb bbbbbbbb.bb bbbbb  bbbbb|
|  bbbbb.bbb bbbbb   bb  bbbbbbbbbbb bbBIbbbbb bb|
|  b bbb.bbb bb bb   bb  bbbbbbb bbb bbIbb  bbibb|
|                                                |
+------------------------------------------------+
#endif

